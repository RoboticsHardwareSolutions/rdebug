cmake_minimum_required(VERSION 3.24)
project(rdebug)

file(GLOB RTT_SOURCES "*.c" "*.s" "*.S")

file(GLOB RTT_HEADERS "*.h")

add_library(${PROJECT_NAME} ${RTT_HEADERS} ${RTT_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        )

#################### FORMAT SECTION #######################

set(FILES_FOR_FORMATTING dwt.c dwt.h )

if (NOT TARGET rlibhelper)
        include(FetchContent)
        FetchContent_Declare(
                rlibhelper
                GIT_REPOSITORY https://github.com/RoboticsHardwareSolutions/rlibhelper.git
                GIT_TAG main
        )
        FetchContent_MakeAvailable(rlibhelper)
endif ()

if(EXISTS "${rlibhelper_SOURCE_DIR}/format.cmake")
        include(${rlibhelper_SOURCE_DIR}/format.cmake)
else()
        message(WARNING "format.cmake file not found")
endif()
format_files(${PROJECT_NAME} SOURCES ${FILES_FOR_FORMATTING})






