#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <sstream>

// Include exercise headers as you complete them
// Uncomment these includes as you implement the exercises:

// #include "../01_function_templates.hpp"
// #include "../02_class_templates.hpp"
// #include "../03_specialization.hpp"
// #include "../04_variadic_templates.hpp"
// #include "../05_sfinae.hpp"
// #include "../06_concepts.hpp"
// #include "../07_advanced.hpp"

/**
 * Template Exercises Test Suite
 *
 * Instructions:
 * 1. Implement exercises in the corresponding .hpp files
 * 2. Uncomment the #include for that exercise file
 * 3. Uncomment the tests for that exercise
 * 4. Run tests: ./build/template_exercises/tests/template_test
 * 5. Fix any failing tests
 * 6. Move to the next exercise
 */

// ============================================================================
// EXERCISE 01: Function Templates Tests
// ============================================================================

// Uncomment these tests after implementing Exercise 01

/*
TEST(Ex01_FunctionTemplates, MyMax) {
    EXPECT_EQ(Ex01::myMax(5, 10), 10);
    EXPECT_EQ(Ex01::myMax(10, 5), 10);
    EXPECT_DOUBLE_EQ(Ex01::myMax(3.14, 2.71), 3.14);
    EXPECT_EQ(Ex01::myMax('a', 'z'), 'z');
}

TEST(Ex01_FunctionTemplates, MySwap) {
    int x = 5, y = 10;
    Ex01::mySwap(x, y);
    EXPECT_EQ(x, 10);
    EXPECT_EQ(y, 5);

    std::string s1 = "hello", s2 = "world";
    Ex01::mySwap(s1, s2);
    EXPECT_EQ(s1, "world");
    EXPECT_EQ(s2, "hello");
}

TEST(Ex01_FunctionTemplates, ConvertAndAdd) {
    auto result1 = Ex01::convertAndAdd<double>(5, 3.14);
    EXPECT_DOUBLE_EQ(result1, 8.14);

    auto result2 = Ex01::convertAndAdd<int>(5.5, 3.7);
    EXPECT_EQ(result2, 8);
}

TEST(Ex01_FunctionTemplates, MakeDefault) {
    auto x = Ex01::makeDefault();
    EXPECT_EQ(x, 0);

    auto y = Ex01::makeDefault<double>();
    EXPECT_DOUBLE_EQ(y, 0.0);
}

TEST(Ex01_FunctionTemplates, PrintContainer) {
    std::vector<int> vec{1, 2, 3};

    // Redirect cout to stringstream for testing
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    Ex01::printContainer(vec);

    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "1 2 3 \n");
}

TEST(Ex01_FunctionTemplates, Power) {
    auto x = Ex01::power<int, 3>(2);
    EXPECT_EQ(x, 8);

    auto y = Ex01::power<double, 2>(3.0);
    EXPECT_DOUBLE_EQ(y, 9.0);

    auto z = Ex01::power<int, 0>(5);
    EXPECT_EQ(z, 1);
}

TEST(Ex01_FunctionTemplates, Multiply) {
    auto x = Ex01::multiply(3, 4.5);
    EXPECT_DOUBLE_EQ(x, 13.5);

    auto y = Ex01::multiply(2.0f, 3.0f);
    EXPECT_FLOAT_EQ(y, 6.0f);
}

TEST(Ex01_FunctionTemplates, Process) {
    auto x = Ex01::process(5);
    EXPECT_EQ(x, 5);

    auto y = Ex01::process(5, 10);
    EXPECT_EQ(y, 15);
}
*/

// ============================================================================
// EXERCISE 02: Class Templates Tests
// ============================================================================

/*
TEST(Ex02_ClassTemplates, FixedArray) {
    Ex02::FixedArray<int, 5> arr;
    arr[0] = 10;
    arr[1] = 20;

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr.size(), 5);
}

TEST(Ex02_ClassTemplates, DynamicArray) {
    Ex02::DynamicArray<int> arr;
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(15);

    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 10);
    EXPECT_EQ(arr[2], 15);
    EXPECT_EQ(arr.size(), 3);
}

TEST(Ex02_ClassTemplates, Pair) {
    Ex02::Pair<int, double> p{5, 3.14};
    EXPECT_EQ(p.first, 5);
    EXPECT_DOUBLE_EQ(p.second, 3.14);
}

TEST(Ex02_ClassTemplates, Stack) {
    Ex02::Stack<int, 100> stack;

    EXPECT_TRUE(stack.empty());

    stack.push(5);
    stack.push(10);

    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.top(), 10);

    stack.pop();
    EXPECT_EQ(stack.top(), 5);

    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(Ex02_ClassTemplates, Container) {
    Ex02::Container<int> c{42};
    EXPECT_EQ(c.getValue(), 42);

    auto d = c.template convertTo<double>();
    EXPECT_DOUBLE_EQ(d, 42.0);
}

TEST(Ex02_ClassTemplates, SmallVector) {
    Ex02::SmallVector<int> vec{1, 2, 3, 4, 5};

    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[4], 5);

    int sum = 0;
    for (auto val : vec) {
        sum += val;
    }
    EXPECT_EQ(sum, 15);
}

TEST(Ex02_ClassTemplates, BinaryTree) {
    Ex02::BinaryTree<int> tree;
    tree.insertRoot(10);

    auto root = tree.getRoot();
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->data, 10);
}

TEST(Ex02_ClassTemplates, Counter) {
    EXPECT_EQ(Ex02::Counter<int>::getCount(), 0);

    {
        Ex02::Counter<int> c1, c2;
        EXPECT_EQ(Ex02::Counter<int>::getCount(), 2);
    }

    EXPECT_EQ(Ex02::Counter<int>::getCount(), 0);
}
*/

// ============================================================================
// EXERCISE 03: Template Specialization Tests
// ============================================================================

/*
TEST(Ex03_Specialization, Compare) {
    EXPECT_TRUE(Ex03::compare(5, 5));
    EXPECT_FALSE(Ex03::compare(5, 10));

    EXPECT_TRUE(Ex03::compare("hello", "hello"));
    EXPECT_FALSE(Ex03::compare("hello", "world"));
}

TEST(Ex03_Specialization, Storage) {
    Ex03::Storage<int> si{42};
    EXPECT_EQ(si.getValue(), 42);

    Ex03::Storage<bool> sb{true};
    EXPECT_TRUE(sb.getValue());

    sb.setValue(false);
    EXPECT_FALSE(sb.getValue());
}

TEST(Ex03_Specialization, TypeInfo) {
    EXPECT_EQ(Ex03::TypeInfo<int>::name(), "Generic type");
    EXPECT_EQ(Ex03::TypeInfo<int*>::name(), "Pointer type");
    EXPECT_EQ(Ex03::TypeInfo<int&>::name(), "Reference type");
}

TEST(Ex03_Specialization, GetDefaultValue) {
    auto i = Ex03::getDefaultValue<int>();
    EXPECT_EQ(i, 0);

    auto d = Ex03::getDefaultValue<double>();
    EXPECT_DOUBLE_EQ(d, 0.0);

    auto s = Ex03::getDefaultValue<std::string>();
    EXPECT_EQ(s, "default");

    auto p = Ex03::getDefaultValue<int*>();
    EXPECT_EQ(p, nullptr);
}

TEST(Ex03_Specialization, PairProcessor) {
    EXPECT_EQ(Ex03::PairProcessor<int, double>::process(), "Different types");
    EXPECT_EQ(Ex03::PairProcessor<double, double>::process(), "Same types");
    EXPECT_EQ(Ex03::PairProcessor<int, int>::process(), "Both integers");
}
*/

// ============================================================================
// EXERCISE 04: Variadic Templates Tests
// ============================================================================

/*
TEST(Ex04_VariadicTemplates, Print) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    Ex04::print(1, 2.5, "hello", 'c');

    std::cout.rdbuf(old);
    // Note: exact output format depends on implementation
}

TEST(Ex04_VariadicTemplates, Sum) {
    auto x = Ex04::sum(1, 2, 3, 4, 5);
    EXPECT_EQ(x, 15);

    auto y = Ex04::sum(1.5, 2.5);
    EXPECT_DOUBLE_EQ(y, 4.0);
}

TEST(Ex04_VariadicTemplates, CountArgs) {
    EXPECT_EQ(Ex04::countArgs(1, "hi", 3.14), 3);
    EXPECT_EQ(Ex04::countArgs(), 0);
    EXPECT_EQ(Ex04::countArgs(1), 1);
}

TEST(Ex04_VariadicTemplates, Average) {
    auto avg = Ex04::average(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(avg, 2.5);
}

TEST(Ex04_VariadicTemplates, Tuple) {
    Ex04::Tuple<int, double, std::string> t{42, 3.14, "hello"};

    EXPECT_EQ(t.template get<0>(), 42);
    EXPECT_DOUBLE_EQ(t.template get<1>(), 3.14);
    EXPECT_EQ(t.template get<2>(), "hello");
    EXPECT_EQ(t.size(), 3);
}

TEST(Ex04_VariadicTemplates, Maximum) {
    auto m = Ex04::maximum(3, 7, 2, 9, 4);
    EXPECT_EQ(m, 9);
}

TEST(Ex04_VariadicTemplates, MakeVector) {
    auto vec = Ex04::makeVector<double>(1, 2.5, 3);

    EXPECT_EQ(vec.size(), 3);
    EXPECT_DOUBLE_EQ(vec[0], 1.0);
    EXPECT_DOUBLE_EQ(vec[1], 2.5);
    EXPECT_DOUBLE_EQ(vec[2], 3.0);
}

TEST(Ex04_VariadicTemplates, AllTrue) {
    EXPECT_TRUE(Ex04::allTrue(true, true, true));
    EXPECT_FALSE(Ex04::allTrue(true, false, true));
    EXPECT_TRUE(Ex04::allTrue());  // Empty case
}

TEST(Ex04_VariadicTemplates, AnyTrue) {
    EXPECT_TRUE(Ex04::anyTrue(false, false, true));
    EXPECT_FALSE(Ex04::anyTrue(false, false, false));
    EXPECT_FALSE(Ex04::anyTrue());  // Empty case
}
*/

// ============================================================================
// EXERCISE 05: SFINAE Tests
// ============================================================================

/*
TEST(Ex05_SFINAE, Process) {
    auto a = Ex05::process(10);
    EXPECT_EQ(a, 20);  // integral: doubled

    auto b = Ex05::process(10.0);
    EXPECT_DOUBLE_EQ(b, 5.0);  // floating: halved
}

TEST(Ex05_SFINAE, Stringify) {
    auto s1 = Ex05::stringify(42);
    EXPECT_EQ(s1, "42");

    auto s2 = Ex05::stringify(3.14);
    EXPECT_TRUE(s2.find("3.14") != std::string::npos);
}

TEST(Ex05_SFINAE, GetSize) {
    std::vector<int> v{1, 2, 3};
    auto s1 = Ex05::getSize(v);
    EXPECT_EQ(s1, 3);

    auto s2 = Ex05::getSize(42);
    EXPECT_EQ(s2, 1);
}

TEST(Ex05_SFINAE, SafeDivide) {
    auto a = Ex05::safeDivide(10, 2);
    EXPECT_TRUE(a.has_value());
    EXPECT_EQ(a.value(), 5);

    auto b = Ex05::safeDivide(10, 0);
    EXPECT_FALSE(b.has_value());

    auto c = Ex05::safeDivide(10.0, 0.0);
    EXPECT_TRUE(std::isinf(c));
}
*/

// ============================================================================
// EXERCISE 06: Concepts Tests (C++20)
// ============================================================================

/*
TEST(Ex06_Concepts, Square) {
    auto x = Ex06::square(5);
    EXPECT_EQ(x, 25);

    auto y = Ex06::square(3.14);
    EXPECT_NEAR(y, 9.8596, 0.0001);
}

TEST(Ex06_Concepts, GetMin) {
    auto m = Ex06::getMin(5, 10);
    EXPECT_EQ(m, 5);
}

TEST(Ex06_Concepts, PrintSize) {
    std::vector<int> v{1, 2, 3};

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    Ex06::printSize(v);

    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "3\n");
}

TEST(Ex06_Concepts, CountIf) {
    std::vector<int> v{1, 2, 3, 4, 5};
    auto n = Ex06::countIf(v, [](int x) { return x > 3; });
    EXPECT_EQ(n, 2);
}

TEST(Ex06_Concepts, ProcessOverloads) {
    auto a = Ex06::process(10);
    EXPECT_EQ(a, 20);

    auto b = Ex06::process(10.0);
    EXPECT_DOUBLE_EQ(b, 5.0);
}

TEST(Ex06_Concepts, SumRange) {
    std::vector<int> v{1, 2, 3, 4, 5};
    auto s = Ex06::sumRange(v);
    EXPECT_EQ(s, 15);
}
*/

// ============================================================================
// EXERCISE 07: Advanced Templates Tests
// ============================================================================

/*
TEST(Ex07_Advanced, Fibonacci) {
    EXPECT_EQ(Ex07::Fibonacci<0>::value, 0);
    EXPECT_EQ(Ex07::Fibonacci<1>::value, 1);
    EXPECT_EQ(Ex07::Fibonacci<5>::value, 5);
    EXPECT_EQ(Ex07::Fibonacci<10>::value, 55);
}

TEST(Ex07_Advanced, TypeListLength) {
    using List = Ex07::TypeList<int, double, char>;
    EXPECT_EQ(Ex07::Length<List>::value, 3);
}

TEST(Ex07_Advanced, IsPrime) {
    EXPECT_TRUE(Ex07::IsPrime<2>::value);
    EXPECT_TRUE(Ex07::IsPrime<7>::value);
    EXPECT_FALSE(Ex07::IsPrime<9>::value);
    EXPECT_TRUE(Ex07::IsPrime<13>::value);
}

TEST(Ex07_Advanced, MyIsPointer) {
    EXPECT_TRUE(Ex07::MyIsPointer<int*>::value);
    EXPECT_FALSE(Ex07::MyIsPointer<int>::value);
    EXPECT_TRUE(Ex07::MyIsPointer<double*>::value);
}

TEST(Ex07_Advanced, MyRemoveConst) {
    bool same1 = std::is_same_v<Ex07::MyRemoveConst<const int>::type, int>;
    EXPECT_TRUE(same1);

    bool same2 = std::is_same_v<Ex07::MyRemoveConst<int>::type, int>;
    EXPECT_TRUE(same2);
}
*/

// ============================================================================
// Main function
// ============================================================================

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
