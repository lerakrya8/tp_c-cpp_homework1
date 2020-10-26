//
// Created by lerakry on 24.10.2020.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include "utils.h"

double* transposition(Matrix* a, double* b) {
    for ( int i = 0; i < a->rows; ++i ) {
        for ( int j = 0; j < a->columns; ++j ) {
            b[i + a->rows * j] = a->matrix[i][j];
        }
    }
    return b;
}

void transposition_parallel(const Matrix* a, int n_start, int n_end, double* b) {
    for ( int i = n_start; i < n_end; ++i ) {
        for ( int j = 0; j < a->columns; ++j ) {
            b[i + a->rows * j] = a->matrix[i][j];
        }
    }
    exit(0);
}

FILE* get_file(const char* file_name, const char* params) {
    const char file_path[] = "/home/lerakry/tp/program_c++/DZ2/";

    char full_file_path[100];

    snprintf(full_file_path, sizeof full_file_path, "%s%s", file_path, file_name);

    FILE* file = fopen(full_file_path, params);

    if ( file == NULL ) {
//        perror(file_name);
//        exit(EXIT_FAILURE);
        return NULL;
    }
    return file;
}

Matrix* get_matrix(FILE* file) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix) * 1);
    if ( matrix == NULL ) {
        return NULL;
    }

    fscanf(file, "%d", &matrix->rows);
    fscanf(file, "%d", &matrix->columns);

    matrix->matrix = (double**) malloc(matrix->rows * sizeof(double*));
    if ( matrix->matrix == NULL ) {
        free(matrix);
        return NULL;
    }
    for (int i = 0; i < matrix->rows; ++i) {
        matrix->matrix[i] = (double*) malloc(matrix->columns * sizeof(double));
        if ( matrix->matrix[i] == NULL ) {
            free(matrix->matrix);
            free(matrix);
            return NULL;
        }
    }

    double number;
    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->columns && fscanf(file, "%lf", &number) == 1; ++j) {
            matrix->matrix[i][j] = number;
        }
    }
    return matrix;
}

int create_processes(int processes_number, int* processes_name) {
    int result = -1;
    for ( int i = 0; i < processes_number; ++i ) {
        int pid = fork();
        if ( pid == 0 ) {
            return ++result;
        }
        ++result;
        if ( pid != -1 ) {
            processes_name[i] = pid;
        }
    }
    return -2;
}

int generate_process_num(int rows) {
    if ( rows == 1 ) {
        return 1;
    }
    if ( rows <= 8 ) {
        return 2;
    }
    if ( rows > 8 && rows <= 1000 ) {
        return rows;
    }
    return 1000;
}

double* split_process(const Matrix* a, double* b) {
    int processes_number = generate_process_num(a->rows);
    int* process_names = (int*)malloc(processes_number * sizeof(int));
    if ( process_names == NULL ) {
        return NULL;
    }
    int j_strings = a->rows / processes_number;
    int num_pid = create_processes(processes_number, process_names);
    if ( num_pid != -2 ) {
        int j_start = num_pid * j_strings;
        int j_end = j_start + j_strings;

        if (a->rows % processes_number != 0 && num_pid == processes_number - 1) {
            j_end = a->rows;
        }
        transposition_parallel(a, j_start, j_end, b);
    }

    printf("proc num , %d\n", processes_number);
    for ( int i = 0; i != processes_number; ++i ) {
        while ( waitpid(process_names[i], NULL, 0) > 0 ) {} }

    free(process_names);
    return b;
}

bool correct_transposition(const double* a1, const double* a2, int matrix_size) {
    for ( int i = 0; i < matrix_size; ++i ) {
        if ( a1[i] != a2[i] ) {
            return false;
        }
    }
    return true;
}

double* shared_memory(int rows, int columns) {
    double* addr = mmap(NULL, rows * columns * sizeof(double), PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if ( addr == NULL ) {
        return NULL;
    }

    return addr;
}

void free_memory(Matrix* matrix) {
    for ( int i = 0; i < matrix->rows; ++i ) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

bool right_matrix(double** a, int rows, int columns, const double* b) {
    for ( int i = 0; i < rows; ++i ) {
        for ( int j = 0; j < columns; ++j ) {
            if ( a[i][j] != *(b + i * columns + j) ) {
                return false;
            }
        }
    }
    return true;
}


