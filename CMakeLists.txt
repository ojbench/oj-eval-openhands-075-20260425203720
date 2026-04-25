

cmake_minimum_required(VERSION 3.10)
project(str_problem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a simple executable that includes str.hpp
add_executable(code main.cpp)

# We need to create a main.cpp file that will be used to compile the code
# The OJ will compile this and use the str.hpp implementation

