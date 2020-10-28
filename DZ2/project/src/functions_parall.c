//
// Created by lerakry on 27.10.2020.
//
#include "utils.h"
#include <sys/wait.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils_parall.h"

void transposition_parallel(const Matrix* a, int n_start, int n_end, double* b) {
    for ( int i = n_start; i < n_end; ++i ) {
        for ( int j = 0; j < a->columns; ++j ) {
            b[i + a->rows * j] = a->matrix[i][j];
        }
    }
    exit(0);
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
        return rows / 8;
    }
    return 10;
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

    for ( int i = 0; i != processes_number; ++i ) {
        while ( waitpid(process_names[i], NULL, 0) > 0 ) {} }

    free(process_names);
    return b;
}

double* shared_memory(int rows, int columns) {
    double* addr = mmap(NULL, rows * columns * sizeof(double), PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if ( addr == NULL ) {
        return NULL;
    }

    return addr;
}

