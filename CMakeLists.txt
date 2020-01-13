cmake_minimum_required(VERSION 3.10)

project(SampleNodeMap)

include_directories(include gtest)

file(GLOB SOURCES "source/*.cpp" "include/*.hpp")

add_executable(SampleNodeMap ${SOURCES})

