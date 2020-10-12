cmake_minimum_required(VERSION 3.17)
project(DZ1 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

#set(CMAKE_EXE_LINKER_FLAGS "-lgtest_main")


include_directories("${GTEST_INCLUDE_DIRS}")

add_executable(testing project/main.cpp project/functions.c)

target_include_directories(testing PUBLIC project/diet.h)

target_link_libraries(testing ${GTEST_LIBRARIES} Threads::Threads)
enable_testing()
add_test(testing TEST COMMAND tests)

add_executable(DZ1 project/main.c project/functions.c)

