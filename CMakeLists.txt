cmake_minimum_required(VERSION 3.28)
project(LabProgrammazione)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

set(SOURCE_FILES Temporary.cpp Temporary.h)
add_executable(LabProgrammazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(LabProgrammazione core)
