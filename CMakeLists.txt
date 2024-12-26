cmake_minimum_required(VERSION 3.29)
project(LetsC)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)

add_library(LetsC
    SHARED library.cpp
        src/interface/ilogger.h
        src/interface/idb.h
        src/logger.cpp
        src/logger.h
        src/sqlite.cpp
        src/sqlite.h
)
target_compile_definitions(LetsC PRIVATE DLL_EXPORT)
target_link_libraries(LetsC PRIVATE SQLite::SQLite3)

add_subdirectory(clientc)
