cmake_minimum_required(VERSION 3.0.0)
project(libalg VERSION 0.1.0 LANGUAGES C CXX)

# Set CPP standard to c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include lib to fetch another lib
include(FetchContent)

# Declares dependency on gtest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Make dependency avilable and include it
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Link test file to gtest
enable_testing()
add_subdirectory(tests)
# add_executable(libalg_test tests/libalg_test.cc)
# target_link_libraries(libalg_test GTest::gtest_main libalg)

# gtest_discover_tests(libalg_test)

# Main execs
set(sources libalg.cpp matrix.cpp transforms.cpp)
add_executable(libalg ${sources})
add_library(matrix matrix.hpp matrix.cpp)

# Allows linking subdirectories
add_subdirectory(MathFunctions) # Adds subdirectory to build
target_link_libraries(libalg PUBLIC MathFunctions) # links sqrt.o to libalg.cpp
target_include_directories(libalg PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions"
                          ) # Optional - Allow us to include "sqrt.h" instead of "MathFunctions/sqrt.h"
# target_include_directories(libalg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
