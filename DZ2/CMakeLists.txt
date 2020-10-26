cmake_minimum_required(VERSION 3.9.2)
project(DZ2 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

#set(CMAKE_EXE_LINKER_FLAGS "-lgtest_main")


include_directories("${GTEST_INCLUDE_DIRS}")

add_executable(testing tests/test.cpp project/src/functions.c)

target_include_directories(testing PUBLIC project/headers/utils.h)

target_link_libraries(testing ${GTEST_LIBRARIES} Threads::Threads)
enable_testing()
add_test(testing TEST COMMAND tests)

add_executable(generator project/src/main.cpp)

add_executable(DZ2 project/src/main.c project/headers/utils.h project/src/functions.c)
