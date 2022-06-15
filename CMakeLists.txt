cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Object.cpp Object.h Vehicle.cpp Vehicle.h Transportations.cpp Transportations.h Node.cpp Node.h)
