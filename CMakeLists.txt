cmake_minimum_required(VERSION 3.24)
project(Quadratic-Equation_v2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Quadratic_Equation main.cpp Equation.cpp Equation.hpp Tests.cpp Tests.hpp)
