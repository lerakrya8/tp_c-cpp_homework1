//
// Created by lerakry on 24.10.2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

FILE* get_file(const char* file_name, const char* params) {
    const char file_path[] = "/home/lerakry/github_tp_c_cpp_h1/tp_c-cpp_homework1/DZ2/tests/";

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

bool correct_transposition(const double* a1, const double* a2, int matrix_size) {
    for ( int i = 0; i < matrix_size; ++i ) {
        if ( a1[i] != a2[i] ) {
            return false;
        }
    }
    return true;
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


