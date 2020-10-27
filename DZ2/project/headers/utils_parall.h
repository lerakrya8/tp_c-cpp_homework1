//
// Created by lerakry on 27.10.2020.
//

#ifndef DZ2_UTILS_PARALL_H
#define DZ2_UTILS_PARALL_H

#include "utils.h"

void transposition_parallel(const Matrix* a, int n_start, int n_end, double* b);
int create_processes(int processes_number, int* processes_name);
int generate_process_num(int rows);
double* split_process(const Matrix* a, double* b);
double* shared_memory(int rows, int columns);
#endif //DZ2_UTILS_PARALL_H
