cmake_minimum_required(VERSION 3.9)

project(ScripCpp VERSION 1.0)

add_subdirectory(src/main/scripcpp/utils)

enable_testing()
add_subdirectory(src/test/scripcpp/utils)