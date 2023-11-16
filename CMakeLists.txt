cmake_minimum_required(VERSION 3.25)
project(fast_egypt)

set(CMAKE_CXX_STANDARD 17)

add_executable(fast_egypt main.cpp stream.cpp stream.h position.cpp position.h consts.h engine.cpp engine.h)
