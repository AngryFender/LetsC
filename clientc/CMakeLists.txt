cmake_minimum_required(VERSION 3.26)
project(clientc)

set(CMAKE_C_STANDARD 11)

add_executable(clientc
    main.c
)

target_link_libraries(clientc PRIVATE LetsC)

add_custom_command(
        TARGET clientc
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:LetsC> $<TARGET_FILE_DIR:clientc>
        COMMENT "Copying LetsC.so to the clientc binary directory"
)