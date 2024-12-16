cmake_minimum_required(VERSION 3.29)
project(LetsC)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


add_library(LetsC
    SHARED library.cpp
        src/interface/ilogger.h
        src/logger.cpp
        src/logger.h
)
target_compile_definitions(LetsC PRIVATE DLL_EXPORT)
add_subdirectory(clientc)
