# Include Gtest library from parent
include(GoogleTest)

add_executable(libalg_test libalg_test.cc another_test.cc final_test.cc matrix_test.cc)
target_link_libraries(libalg_test PUBLIC GTest::gtest_main matrix) # needs to be library for linking, not exec

# Sets the target to all be test files
gtest_discover_tests(libalg_test)