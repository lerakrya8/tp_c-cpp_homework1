//
// Created by lerakry on 23.10.2020.
//

#ifndef _HOME_LERAKRY_TP_PROGRAM_C___DZ2_UTILS_H_
#define _HOME_LERAKRY_TP_PROGRAM_C___DZ2_UTILS_H_

#include <stdbool.h>

typedef struct {
    int rows;
    int columns;
    double** matrix;
} Matrix;

double* transposition(Matrix* a, double* b);
void transposition_parallel(const Matrix* a, int n_start, int n_end, double* b);
FILE* get_file(const char* file_name, const char* params);
Matrix* get_matrix(FILE* file);
int create_processes(int processes_number, int* processes_name);
int generate_process_num(int rows);
double* split_process(const Matrix* a, double* b);
bool correct_transposition(const double* a1, const double* a2, int matrix_size);
double* shared_memory(int rows, int columns);
void free_memory(Matrix* matrix);
bool right_matrix(double** a, int rows, int columns, const double* b);

#endif  // _HOME_LERAKRY_TP_PROGRAM_C___DZ2_UTILS_H_
