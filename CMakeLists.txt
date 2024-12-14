cmake_minimum_required(VERSION 3.29)
project(LetsC)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_library(LetsC
    SHARED library.cpp
)

add_subdirectory(clientc)
