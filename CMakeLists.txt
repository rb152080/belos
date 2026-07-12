cmake_minimum_required(VERSION 3.20)
project(belos)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)
#
# project(belos LANGUAGES CXX)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

execute_process(
    COMMAND "${Python3_EXECUTABLE}" -m pybind11 --cmakedir
    OUTPUT_VARIABLE PYBIND11_CMAKE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

list(APPEND CMAKE_PREFIX_PATH "${PYBIND11_CMAKE_DIR}")
find_package(pybind11 REQUIRED)

pybind11_add_module(belos src/vector.cpp)

# add_executable(belos src/vector.cpp)
target_include_directories(belos PRIVATE include)
