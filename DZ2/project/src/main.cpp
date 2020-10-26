
#include <iostream>
#include <string>
#include <random>
#include <fstream>

void matrix_generation(std::ofstream& file, int rows, int columns) {
    //std::random_device rd;
    std::mt19937 mersenne(static_cast<double>(time(nullptr)));

    file << rows << " " << columns << " ";
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
        {
            file << (mersenne() % 100'000) * 0.001 << " ";
        }
}

void create_file(std::string& file_name, int rows, int columns) {
    std::string file_path = "/home/lerakry/tp/program_c++/DZ2/";
    std::ofstream file;
    file.open(file_path + file_name);
    matrix_generation(file, rows, columns);
    file.close();
}


int main()
{
    std::string name_file = "example4x4";
    create_file(name_file, 4, 4);

    return 0;
}

