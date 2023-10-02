cmake_minimum_required(VERSION 3.23)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(leetcode main.cpp object.h python_module.h)

find_package(PythonLibs REQUIRED)
include_directories(/usr/include/python3.7)
