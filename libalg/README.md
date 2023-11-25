# Libalg Project

This project is intended to showcase how a cmake could be used to create a linear algebra solver library that is fully tested.

## Notes

1. For VSCode, Run CMake Configure to update VSCode's linkage to the CMake library e.g. so that it uses gtest instead of ctest
* Just do it to avoid issues with e.g. no tests detected
2. add_subdir - makes root treat subdirectory as one that cmake should care about i.e. can use cmakelists.txt
3. Rerun cmake refresh tests before you run tests again
    * If you just rebuild and run ./build/tests/libalg_test, you get all the gtests refreshed,
    which differs from calling `cmake build && cmake run tests` which does not work and still requires refreshing.
    * Refresh Tests command is same as build command but I think vscode still needs to run it?- `/usr/bin/cmake --build /home/tim/cpp/libalg/build --config Debug --target all -j 14 --`
4. VSCode CMake currently does not support debugging testcases without a debug config, so you should just use Testmate instead (auto does config), and refresh test using ctest.