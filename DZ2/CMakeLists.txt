cmake_minimum_required(VERSION 3.9.2)
project(DZ2 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_C_FLAGS "-g -Wall -Werror -Wextra -O3 -fprofile-arcs -ftest-coverage")
#set(CMAKE_CXX_FLAGS  "-g -Wall -O3 -fprofile-arcs -ftest-coverage")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

#set(CMAKE_EXE_LINKER_FLAGS "-lgtest_main")

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

include_directories("${GTEST_INCLUDE_DIRS}")

include_directories(project/headers)


add_library(compute_parallal SHARED
        project/headers/utils.h
        project/headers/utils_parall.h
        project/src/functions_parall.c
        project/src/functions.c)

add_library(compute_synch STATIC
        project/headers/utils.h
        project/headers/utils_synch.h
        project/src/functions.c
        project/src/functions_synch.c)



add_executable(testing tests/test.cpp)

target_include_directories(testing PUBLIC project/headers/utils.h)

target_link_libraries(testing ${GTEST_LIBRARIES} Threads::Threads compute_synch compute_parallal)
enable_testing()
add_test(testing TEST COMMAND tests)

add_executable(generator tests/main.cpp)

add_executable(DZ2 project/src/main.c)

target_link_libraries(DZ2 compute_parallal compute_synch)
