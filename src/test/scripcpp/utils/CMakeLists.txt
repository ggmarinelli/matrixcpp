add_executable(
	ScripCppUtilsTests
	test_matrix.cpp
)

target_link_libraries(
	ScripCppUtilsTests PRIVATE ScripCppUtils
)

target_include_directories(
	ScripCppUtilsTests PUBLIC "${PROJECT_SOURCE_DIR}/include"
)

add_test(
	NAME ScripCppUtils COMMAND ScripCppUtilsTests
)