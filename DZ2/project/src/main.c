#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <sys/mman.h>

void print(double** matrix, int rows, int columns) {
    for ( int i = 0; i < rows; ++i ) {
        for ( int j = 0; j < columns; ++j ) {
            printf("%g ", matrix[i][j]);
        }
        printf("%s", "\n");
    }
}

void print1(double* matrix, int matrix_size, int k) {
    for ( int i = 0; i < matrix_size; ++i ) {
        printf("%g ", matrix[i]);
        if ( i % k == k - 1 ) {
            printf("%s", "\n");
        }
    }
}

int main() {
    Matrix* a = get_matrix(get_file("matrix20x30", "r"));
    double* b = (double*)malloc((a->columns * a->rows) * sizeof(double));
    double* b1 = shared_memory(a->rows, a->columns);

    print(a->matrix, a->rows, a->columns);
    printf("%s", "Транспонированная матрица: \n");
    b1 = split_process(a, b1);
    b = transposition(a, b);

    print1(b, a->columns * a->rows, a->rows);
    printf("%s", "Транспонированная матрица1: \n");

    print1(b1, a->columns * a->rows, a->rows);
    free_memory(a);
    free(b);
    munmap(b1, a->rows * a->columns);
    return 0;
}
