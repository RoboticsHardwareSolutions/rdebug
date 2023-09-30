cmake_minimum_required(VERSION 3.9)
project(rdebug)

file(GLOB RTT_SOURCES "*.c" "*.s" "*.S")

file(GLOB RTT_HEADERS "*.h")

add_library(${PROJECT_NAME} ${RTT_HEADERS} ${RTT_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        )







