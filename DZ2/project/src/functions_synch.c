//
// Created by lerakry on 27.10.2020.
//
#include "utils.h"
#include "utils_synch.h"

double* transposition(Matrix* a, double* b) {
    for ( int i = 0; i < a->rows; ++i ) {
        for ( int j = 0; j < a->columns; ++j ) {
            b[i + a->rows * j] = a->matrix[i][j];
        }
    }
    return b;
}
