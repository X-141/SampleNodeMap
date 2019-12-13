cmake_minimum_required(VERSION 3.12)

project(SampleNodeMap)

include_directories(include)

file(GLOB SOURCES "source/*.cpp" "include/*.hpp")

add_executable(SampleNodeMap ${SOURCES})
