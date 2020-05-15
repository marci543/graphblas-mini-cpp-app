cmake_minimum_required(VERSION 3.10)
project(graphblas_mini_cpp_app)

set(CMAKE_CXX_STANDARD 11)

link_libraries(graphblas)

add_executable(graphblas_mini_cpp_app main.cpp)
