//
// Created by lerakry on 23.10.2020.
//

#ifndef _HOME_LERAKRY_TP_PROGRAM_C___DZ2_UTILS_H_
#define _HOME_LERAKRY_TP_PROGRAM_C___DZ2_UTILS_H_

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

#endif  // _HOME_LERAKRY_TP_PROGRAM_C___DZ2_UTILS_H_
