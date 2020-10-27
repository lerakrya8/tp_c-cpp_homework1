//
// Created by lerakry on 24.10.2020.
//
#include <gtest/gtest.h>
#include <string>
#include <sys/mman.h>

extern "C" {
    #include "utils_parall.h"
#include "utils_synch.h"
}

TEST(Read_file, compare_matrix_4x4) {
    FILE* file = get_file("example4x4", "r");
    if ( file == nullptr ) {
        return;
    }
    Matrix* matrix = get_matrix(file);
    if ( matrix == nullptr ) {
        free(matrix);
        return;
    }
    int rows = 4, columns = 4;
    double correct_matrix[4][4] = {{60.457, 48.932, 88.998, 2.494},
                                   {94.694, 93.433, 61.753, 98.591},
                                   {78.065, 31.204, 89.86, 13.212},
                                   {63.912, 95.502, 78.58, 11.642}};

    EXPECT_EQ(matrix->rows, rows);
    EXPECT_EQ(matrix->columns, columns);
    EXPECT_EQ(true, right_matrix(matrix->matrix, rows, columns, &correct_matrix[0][0]));
    free_memory(matrix);
}
TEST(Read_file, compare_matrix_5x6) {
    Matrix* matrix = get_matrix(get_file("example5x6", "r"));
    if ( matrix == nullptr ) {
        return;
    }
    int rows = 5, columns = 6;
    double correct_matrix[5][6] = {{46.091, 10.541, 10.282, 91.8, 30.378, 14.011},
                                   {40.977, 95.069, 91.679, 0.097, 29.083, 40.42},
                                   {96.958, 41.468, 29.643, 95.517, 90.43, 47.856},
                                   {14.899, 54.983, 79.64, 38.718, 69.662, 84.932},
                                   {79.696, 59.116, 82.478, 44.332, 1.795, 62.534}};

    EXPECT_EQ(matrix->rows, rows);
    EXPECT_EQ(matrix->columns, columns);
    EXPECT_EQ(true, right_matrix(matrix->matrix, rows, columns, &correct_matrix[0][0]));
    free_memory(matrix);
}

TEST(Compare_matrix, matrix_1x5) {
    Matrix* a = get_matrix(get_file("matrix1x5", "r"));
    if ( a == nullptr ) {
        return;
    }
    auto* b1 = (double*)malloc((a->columns * a->rows) * sizeof(double));
    if ( b1 == nullptr ) {
        return;
    }

    double* b2 = shared_memory(a->rows, a->columns);

    b1 = transposition(a, b1);
    b2 = split_process(a, b2);

    EXPECT_EQ(true, correct_transposition(b1, b2, a->columns * a->rows));

    munmap(b2, a->rows);
    free_memory(a);
    free(b1);
}

TEST(Compare_matrix, matrix_3x4) {
    Matrix* a = get_matrix(get_file("matrix3x4", "r"));
    if ( a == nullptr ) {
        return;
    }
    auto* b1 = (double*)malloc((a->columns * a->rows) * sizeof(double));
    if ( b1 == nullptr ) {
        return;
    }

    double* b2 = shared_memory(a->rows, a->columns);

    b1 = transposition(a, b1);
    b2 = split_process(a, b2);


    EXPECT_EQ(true, correct_transposition(b1, b2, a->columns * a->rows));

    munmap(b2, a->rows);
    free_memory(a);
    free(b1);
}

TEST(Compare_matrix, matrix_8x7) {
    Matrix* a = get_matrix(get_file("matrix8x7", "r"));
    if ( a == nullptr ) {
        return;
    }
    auto* b1 = (double*)malloc((a->columns * a->rows) * sizeof(double));
    if ( b1 == nullptr ) {
        return;
    }

    double* b2 = shared_memory(a->rows, a->columns);

    b1 = transposition(a, b1);
    b2 = split_process(a, b2);


    EXPECT_EQ(true, correct_transposition(b1, b2, a->columns * a->rows));

    munmap(b2, a->rows);
    free_memory(a);
    free(b1);
}

TEST(Compare_matrix, matrix_20x30) {
    Matrix* a = get_matrix(get_file("matrix20x30", "r"));
    if ( a == nullptr ) {
        return;
    }
    auto* b1 = (double*)malloc((a->columns * a->rows) * sizeof(double));
    if ( b1 == nullptr ) {
        return;
    }

    double* b2 = shared_memory(a->rows, a->columns);

    b1 = transposition(a, b1);
    b2 = split_process(a, b2);


    EXPECT_EQ(true, correct_transposition(b1, b2, a->columns * a->rows));

    munmap(b2, a->rows);
    free_memory(a);
    free(b1);
}

TEST(Compare_matrix, matrix_100x100) {
    Matrix* a = get_matrix(get_file("matrix100x100", "r"));
    if ( a == nullptr ) {
        return;
    }
    auto* b1 = (double*)malloc((a->columns * a->rows) * sizeof(double));
    if ( b1 == nullptr ) {
        return;
    }

    double* b2 = shared_memory(a->rows, a->columns);

    b1 = transposition(a, b1);
    b2 = split_process(a, b2);


    EXPECT_EQ(true, correct_transposition(b1, b2, a->columns * a->rows));

    munmap(b2, a->rows);
    free_memory(a);
    free(b1);
}

TEST(Compare_matrix, matrix_500x600) {
    Matrix* a = get_matrix(get_file("matrix500x600", "r"));
    if ( a == nullptr ) {
        return;
    }
    auto* b1 = (double*)malloc((a->columns * a->rows) * sizeof(double));
    if ( b1 == nullptr ) {
        return;
    }

    double* b2 = shared_memory(a->rows, a->columns);

    b1 = transposition(a, b1);
    b2 = split_process(a, b2);


    EXPECT_EQ(true, correct_transposition(b1, b2, a->columns * a->rows));

    munmap(b2, a->rows);
    free_memory(a);
    free(b1);
}

TEST(Compare_matrix, matrix_1000x2000) {
    Matrix* a = get_matrix(get_file("matrix1000x2000", "r"));
    if ( a == nullptr ) {
        return;
    }
    auto* b1 = (double*)malloc((a->columns * a->rows) * sizeof(double));
    if ( b1 == nullptr ) {
        return;
    }

    double* b2 = shared_memory(a->rows, a->columns);

    b1 = transposition(a, b1);
    b2 = split_process(a, b2);


    EXPECT_EQ(true, correct_transposition(b1, b2, a->columns * a->rows));

    munmap(b2, a->rows);
    free_memory(a);
    free(b1);
}

TEST(Compare_matrix, matrix_10000x5000) {
    Matrix* a = get_matrix(get_file("matrix10000x5000", "r"));
    if ( a == nullptr ) {
        return;
    }
    auto* b1 = (double*)malloc((a->columns * a->rows) * sizeof(double));
    if ( b1 == nullptr ) {
        return;
    }

    double* b2 = shared_memory(a->rows, a->columns);

    b1 = transposition(a, b1);
    b2 = split_process(a, b2);


    EXPECT_EQ(true, correct_transposition(b1, b2, a->columns * a->rows));

    munmap(b2, a->rows);
    free_memory(a);
    free(b1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


