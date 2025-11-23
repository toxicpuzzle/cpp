# Template Exercises Test Suite

# Create test executable
add_executable(
    template_test
    template_exercises_test.cc
)

# Link with GoogleTest
target_link_libraries(
    template_test
    GTest::gtest_main
)

# Include parent directory for exercise headers
target_include_directories(template_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Discover tests
include(GoogleTest)
gtest_discover_tests(template_test)
