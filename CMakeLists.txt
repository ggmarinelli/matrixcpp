cmake_minimum_required(VERSION 3.9)

project(ScripCpp VERSION 1.0)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

add_subdirectory(src/main/scripcpp/risk_functions)
add_subdirectory(src/main/scripcpp/utils)

enable_testing()
add_subdirectory(src/test/scripcpp/utils)