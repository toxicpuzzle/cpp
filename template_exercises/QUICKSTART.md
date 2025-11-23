# Quick Start Guide

Get up and running with the template exercises in 5 minutes!

## 🎯 Quick Setup

```bash
# Navigate to the exercises directory
cd /home/user/cpp/template_exercises

# Configure CMake
cmake -B build

# Build the tests
cmake --build build

# Run the tests
./build/tests/template_test
```

## ✅ Your First Exercise

Let's complete Exercise 1.1 together!

### 1. Open the exercise file
```bash
vim 01_function_templates.hpp
# or use your favorite editor
```

### 2. Find Exercise 1.1 (around line 17)
Look for:
```cpp
// EXERCISE 1.1: Basic Function Template
// TODO: Implement a template function 'myMax'
```

### 3. Implement the solution
Replace `YOUR CODE HERE:` with:

```cpp
template<typename T>
T myMax(T x, T y) {
    return (x < y) ? y : x;
}
```

### 4. Enable the tests
Open `tests/template_exercises_test.cc` and:

**Uncomment line 11:**
```cpp
#include "../01_function_templates.hpp"
```

**Uncomment lines 31-38:**
```cpp
TEST(Ex01_FunctionTemplates, MyMax) {
    EXPECT_EQ(Ex01::myMax(5, 10), 10);
    EXPECT_EQ(Ex01::myMax(10, 5), 10);
    EXPECT_DOUBLE_EQ(Ex01::myMax(3.14, 2.71), 3.14);
    EXPECT_EQ(Ex01::myMax('a', 'z'), 'z');
}
```

### 5. Build and test
```bash
cmake --build build
./build/tests/template_test --gtest_filter=Ex01_FunctionTemplates.MyMax
```

### 6. Expected output
```
[==========] Running 1 test from 1 test suite.
[----------] 1 test from Ex01_FunctionTemplates
[ RUN      ] Ex01_FunctionTemplates.MyMax
[       OK ] Ex01_FunctionTemplates.MyMax (0 ms)
[----------] 1 test from Ex01_FunctionTemplates (0 ms total)

[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
```

🎉 **Congratulations!** You've completed your first template exercise!

## 📚 Continue Learning

Now continue with the remaining exercises in `01_function_templates.hpp`:
- 1.2: mySwap
- 1.3: convertAndAdd
- 1.4: makeDefault
- ... and more!

For each one:
1. Implement in the .hpp file
2. Uncomment the corresponding test
3. Build and run tests
4. Fix any errors
5. Move to the next!

## 🔥 Pro Tips

### Run specific test suites
```bash
# Run all Exercise 01 tests
./build/tests/template_test --gtest_filter=Ex01*

# Run all Exercise 02 tests
./build/tests/template_test --gtest_filter=Ex02*
```

### Watch mode (rebuild on change)
```bash
# In one terminal, watch for changes and rebuild:
while true; do inotifywait -e modify *.hpp tests/*.cc && cmake --build build; done

# In another terminal, run tests:
./build/tests/template_test
```

### See verbose test output
```bash
./build/tests/template_test --gtest_filter=Ex01* --gtest_print_time=1 --gtest_color=yes
```

### Build faster
```bash
cmake --build build -j$(nproc)  # Parallel build
```

## 🐛 Common Issues

**Issue:** Tests compile but all are skipped
**Solution:** Make sure you uncommented both the include AND the test cases

**Issue:** "undefined reference" error
**Solution:** Static member variables need to be defined outside the class

**Issue:** "no matching function" error
**Solution:** Check namespace - functions are in `Ex01::`, `Ex02::`, etc.

**Issue:** Concept errors with C++20
**Solution:** Make sure CMakeLists.txt has `set(CMAKE_CXX_STANDARD 20)`

## 📖 Full Documentation

For detailed information, see [README.md](README.md)

Happy templating! 🚀
