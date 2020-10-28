
#include <iostream>
#include <string>
#include <random>
#include <fstream>

void matrix_generation(std::ofstream& file, int rows, int columns) {
    //std::random_device rd;
    std::mt19937 mersenne(static_cast<double>(time(nullptr)));

    file << rows << " " << columns << " ";
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            file << mersenne() % 100000 * 0.001 << " ";

        }
    }
}

void create_file(std::string& file_name, int rows, int columns) {
    std::string file_path = "/home/lerakry/github_tp_c_cpp_h1/tp_c-cpp_homework1/DZ2/tests/";
    std::ofstream file;
    file.open(file_path + file_name);
    matrix_generation(file, rows, columns);
    file.close();
}


int main(int argc, char *argv[])
{
    //std::string name_file = "matrix10000x5000";
    std::string name_file = argv[1];
    int rows = atoi(argv[2]);
    int columns = atoi(argv[3]);
    create_file(name_file, rows, columns);

    return 0;
}

