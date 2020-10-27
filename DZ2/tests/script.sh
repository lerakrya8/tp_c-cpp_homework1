#!/usr/bin/env bash

g++ -std=c++14 main.cpp -o create_matrix
./create_matrix matrix1x5 1 5
./create_matrix matrix3x4 3 4
./create_matrix matrix8x7 8 7
./create_matrix matrix20x30 20 30
./create_matrix matrix100x100 100 100
./create_matrix matrix500x600 500 600
./create_matrix matrix1000x2000 1000 2000
./create_matrix matrix10000x5000 10000 5000