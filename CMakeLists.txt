cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Person.cpp Person.h Student.cpp Student.h Class.cpp Class.h Node.cpp Node.h)
