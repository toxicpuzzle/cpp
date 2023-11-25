# Include Gtest library from parent
include(GoogleTest)

add_executable(libalg_test libalg_test.cc another_test.cc final_test.cc)
target_link_libraries(libalg_test GTest::gtest_main)

# Sets the target to all be test files
gtest_discover_tests(libalg_test)