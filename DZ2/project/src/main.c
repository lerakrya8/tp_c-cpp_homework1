#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <sys/mman.h>
#include <time.h>
#include <utils_parall.h>
#include <utils_synch.h>

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
    Matrix* a = get_matrix(get_file("matrix10000x5000", "r"));
    double* b = (double*)malloc((a->columns * a->rows) * sizeof(double));
    double* b1 = shared_memory(a->rows, a->columns);

    clock_t begin_synch = clock();
    b = transposition(a, b);
    clock_t end_synch = clock();
    double time_spent_synch = (double)(end_synch - begin_synch) * 1000.0 / CLOCKS_PER_SEC;

    clock_t begin_parall = clock();
    b1 = split_process(a, b1);
    clock_t end_parall = clock();
    double time_spent_parall = (double)(end_parall - begin_parall) * 1000.0 / CLOCKS_PER_SEC;

    bool correct_trans = correct_transposition(b, b1, a->rows * a->columns);

    if ( correct_trans ) {
        printf("%s\n", "Транспонирование верно");
    } else {
        printf("%s\n", "Транспонирование неверно");
    }

    printf("Синхронно: %g мс\n", time_spent_synch);
    printf("Многопроцессорно: %g мс", time_spent_parall);
    free_memory(a);
    free(b);
    munmap(b1, a->rows * a->columns);
    return 0;
}
