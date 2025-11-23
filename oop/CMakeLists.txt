cmake_minimum_required(VERSION 3.14)
project(OOP_Exercises_Tests)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Create library targets for each OOP class (without main functions)
add_library(ball_lib INTERFACE)
target_include_directories(ball_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Ball)

add_library(intpair_lib INTERFACE)
target_include_directories(intpair_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/IntPair)

add_library(point3d_lib INTERFACE)
target_include_directories(point3d_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Point3d)

add_library(rgba_lib INTERFACE)
target_include_directories(rgba_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/RGBA)

add_library(stack_lib INTERFACE)
target_include_directories(stack_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Stack)

# Create test executable
add_executable(
  oop_tests
  tests/oop_test.cc
)

# Link test executable with GoogleTest and OOP libraries
target_link_libraries(
  oop_tests
  GTest::gtest_main
  ball_lib
  intpair_lib
  point3d_lib
  rgba_lib
  stack_lib
)

# Add tests to CTest
include(GoogleTest)
gtest_discover_tests(oop_tests)
