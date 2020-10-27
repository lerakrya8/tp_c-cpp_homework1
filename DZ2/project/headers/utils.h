//
// Created by lerakry on 23.10.2020.
//

#ifndef DZ2_PROJECT_HEADERS_UTILS_H_
#define DZ2_PROJECT_HEADERS_UTILS_H_

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int rows;
    int columns;
    double** matrix;
} Matrix;

FILE* get_file(const char* file_name, const char* params);
Matrix* get_matrix(FILE* file);
bool correct_transposition(const double* a1, const double* a2, int matrix_size);
void free_memory(Matrix* matrix);
bool right_matrix(double** a, int rows, int columns, const double* b);

#endif  // DZ2_PROJECT_HEADERS_UTILS_H_
