add_library(
    scripcpp-risk-functions
    base_function.cpp
    vol_function.cpp)

target_include_directories(scripcpp-risk-functions PUBLIC "${PROJECT_SOURCE_DIR}/include")