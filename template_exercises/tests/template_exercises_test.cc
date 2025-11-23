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
// #include "../08_x_macros.hpp"
// #include "../09_pimpl.hpp"
// #include "../10_cpp_idioms.hpp"
// #include "../11_design_patterns.hpp"
// #include "../12_type_techniques.hpp"
// #include "../13_stl_ranges.hpp"
// #include "../14_functional_programming.hpp"
// #include "../15_performance_patterns.hpp"
// #include "../16_move_semantics.hpp"

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
// EXERCISE 08: X Macros Tests
// ============================================================================

/*
TEST(Ex08_XMacros, ColorEnumAndString) {
    Ex08::Color c = Ex08::Color::RED;
    std::string s = Ex08::colorToString(c);
    EXPECT_EQ(s, "RED");

    Ex08::Color c2 = Ex08::stringToColor("GREEN");
    EXPECT_EQ(c2, Ex08::Color::GREEN);
}

TEST(Ex08_XMacros, ErrorCodes) {
    Ex08::ErrorCode err = Ex08::ErrorCode::FILE_NOT_FOUND;
    std::string msg = Ex08::getErrorMessage(err);
    EXPECT_EQ(msg, "The specified file was not found");

    std::string name = Ex08::getErrorName(err);
    EXPECT_EQ(name, "FILE_NOT_FOUND");
}

TEST(Ex08_XMacros, ExecuteCommand) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    Ex08::executeCommand(Ex08::Command::START);

    std::cout.rdbuf(old);
    EXPECT_TRUE(buffer.str().find("START") != std::string::npos);
}

TEST(Ex08_XMacros, Calculate) {
    EXPECT_EQ(Ex08::calculate(Ex08::Operation::ADD, 5, 3), 8);
    EXPECT_EQ(Ex08::calculate(Ex08::Operation::MUL, 5, 3), 15);
    EXPECT_EQ(Ex08::calculate(Ex08::Operation::SUB, 5, 3), 2);
}

TEST(Ex08_XMacros, BitFlags) {
    unsigned int flags = 0;
    Ex08::setFlag(flags, Ex08::FLAG_READ);
    Ex08::setFlag(flags, Ex08::FLAG_WRITE);

    EXPECT_TRUE(Ex08::hasFlag(flags, Ex08::FLAG_READ));
    EXPECT_TRUE(Ex08::hasFlag(flags, Ex08::FLAG_WRITE));
    EXPECT_FALSE(Ex08::hasFlag(flags, Ex08::FLAG_EXECUTE));
}
*/

// ============================================================================
// EXERCISE 09: PIMPL Idiom Tests
// ============================================================================

/*
TEST(Ex09_PIMPL, BasicWidget) {
    Ex09::Widget w;
    w.setName("MyWidget");
    EXPECT_EQ(w.getName(), "MyWidget");
    w.doWork();
}

TEST(Ex09_PIMPL, CopyablePerson) {
    Ex09::Person p1{"John", 30, "123 Main St"};
    Ex09::Person p2 = p1;  // copy

    EXPECT_EQ(p1.getName(), "John");
    EXPECT_EQ(p2.getName(), "John");

    Ex09::Person p3 = std::move(p1);  // move
    EXPECT_EQ(p3.getName(), "John");
}

TEST(Ex09_PIMPL, SharedData) {
    Ex09::SharedData d1;
    d1.setValue(42);

    Ex09::SharedData d2 = d1;  // shares implementation
    d2.setValue(100);

    EXPECT_EQ(d1.getValue(), 100);  // both see the change

    Ex09::SharedData d3 = d2.clone();  // deep copy
    d3.setValue(200);
    EXPECT_EQ(d2.getValue(), 100);  // d2 unchanged
}

TEST(Ex09_PIMPL, DatabaseResource) {
    Ex09::Database db;
    db.connect("localhost:5432");
    db.execute("SELECT * FROM users");
    db.disconnect();
}

TEST(Ex09_PIMPL, ThreadSafeCounter) {
    Ex09::ThreadSafeCounter counter;
    counter.increment();
    counter.increment();
    EXPECT_EQ(counter.get(), 2);
    counter.decrement();
    EXPECT_EQ(counter.get(), 1);
}
*/

// ============================================================================
// EXERCISE 10: C++ Idioms Tests
// ============================================================================

/*
TEST(Ex10_Idioms, RAIIFileHandle) {
    {
        Ex10::FileHandle file("test.txt", "w");
        EXPECT_TRUE(file.isOpen());
        file.write("test data");
    }  // file automatically closed
}

TEST(Ex10_Idioms, RuleOfZero) {
    Ex10::DataContainer dc;
    dc.addValue(42);
    dc.addValue(100);
    EXPECT_EQ(dc.getValue(0), 42);
    EXPECT_EQ(dc.getValue(1), 100);
}

TEST(Ex10_Idioms, RuleOfThree) {
    Ex10::Array a1(10);
    a1[0] = 42;

    Ex10::Array a2 = a1;  // copy constructor
    EXPECT_EQ(a2[0], 42);

    Ex10::Array a3(5);
    a3 = a1;  // copy assignment
    EXPECT_EQ(a3[0], 42);
}

TEST(Ex10_Idioms, RuleOfFive) {
    Ex10::Buffer b1(1024);
    b1.write(42);

    Ex10::Buffer b2 = std::move(b1);  // move constructor
    EXPECT_EQ(b2.read(), 42);

    Ex10::Buffer b3(512);
    b3 = std::move(b2);  // move assignment
    EXPECT_EQ(b3.read(), 42);
}

TEST(Ex10_Idioms, CopyAndSwap) {
    Ex10::String s1("Hello");
    Ex10::String s2("World");

    s1 = s2;  // uses copy-and-swap
    EXPECT_EQ(s1.c_str(), std::string("World"));
}

TEST(Ex10_Idioms, NamedParameter) {
    Ex10::HttpRequest req;
    req.setUrl("http://example.com")
       .setMethod("POST")
       .setTimeout(30)
       .execute();
}

TEST(Ex10_Idioms, StrongType) {
    Ex10::UserId userId{42};
    Ex10::ProductId productId{42};

    EXPECT_EQ(userId.get(), 42);
    EXPECT_EQ(productId.get(), 42);

    // userId == productId;  // should not compile
}

TEST(Ex10_Idioms, ScopeGuard) {
    bool cleaned = false;
    {
        Ex10::ScopeGuard guard([&cleaned]{ cleaned = true; });
        EXPECT_FALSE(cleaned);
    }
    EXPECT_TRUE(cleaned);
}
*/

// ============================================================================
// EXERCISE 11: Design Patterns Tests
// ============================================================================

/*
TEST(Ex11_DesignPatterns, Singleton) {
    auto& logger1 = Ex11::Logger::getInstance();
    auto& logger2 = Ex11::Logger::getInstance();

    // Same instance
    EXPECT_EQ(&logger1, &logger2);

    logger1.log("Test message");
}

TEST(Ex11_DesignPatterns, Factory) {
    auto dog = Ex11::AnimalFactory::createAnimal("dog");
    auto cat = Ex11::AnimalFactory::createAnimal("cat");

    EXPECT_NE(dog, nullptr);
    EXPECT_NE(cat, nullptr);

    dog->speak();  // "Woof!"
    cat->speak();  // "Meow!"
}

TEST(Ex11_DesignPatterns, Builder) {
    auto pizza = Ex11::PizzaBuilder()
        .setSize("large")
        .addTopping("pepperoni")
        .addTopping("mushrooms")
        .setCrust("thin")
        .build();

    EXPECT_NE(pizza, nullptr);
}

TEST(Ex11_DesignPatterns, Observer) {
    auto subject = std::make_shared<Ex11::Subject>();
    auto obs1 = std::make_shared<Ex11::ConcreteObserver>();

    subject->attach(obs1);
    subject->setState(42);
    // obs1 should be notified
}

TEST(Ex11_DesignPatterns, Strategy) {
    Ex11::Context ctx;
    ctx.setStrategy([](int a, int b) { return a + b; });
    EXPECT_EQ(ctx.executeStrategy(5, 3), 8);

    ctx.setStrategy([](int a, int b) { return a * b; });
    EXPECT_EQ(ctx.executeStrategy(5, 3), 15);
}

TEST(Ex11_DesignPatterns, Command) {
    Ex11::CommandInvoker invoker;
    invoker.executeCommand(std::make_unique<Ex11::AddCommand>(5));
    // Can undo/redo
    invoker.undo();
}

TEST(Ex11_DesignPatterns, State) {
    Ex11::TCPConnection conn;
    conn.open();     // transitions to Listen
    conn.connect();  // transitions to Established
    conn.close();    // transitions to Closed
}
*/

// ============================================================================
// EXERCISE 12: Type Techniques Tests
// ============================================================================

/*
TEST(Ex12_TypeTechniques, SimpleAny) {
    Ex12::SimpleAny a = 42;
    EXPECT_TRUE(a.has_value());
    EXPECT_EQ(a.get<int>(), 42);

    EXPECT_THROW(a.get<std::string>(), std::bad_cast);
}

TEST(Ex12_TypeTechniques, FunctionWrapper) {
    Ex12::Function<int(int, int)> f = [](int a, int b) { return a + b; };
    EXPECT_EQ(f(3, 4), 7);
}

TEST(Ex12_TypeTechniques, StrongTypes) {
    Ex12::Meters distance{100};
    Ex12::Seconds time{10};

    EXPECT_EQ(distance.get(), 100);
    EXPECT_EQ(time.get(), 10);

    // distance / time;  // should not compile
}

TEST(Ex12_TypeTechniques, ResultType) {
    Ex12::Result<int, std::string> r1 = Ex12::ok(42);
    EXPECT_TRUE(r1.isOk());
    EXPECT_EQ(r1.unwrap(), 42);

    Ex12::Result<int, std::string> r2 = Ex12::err(std::string("error"));
    EXPECT_TRUE(r2.isErr());
}

TEST(Ex12_TypeTechniques, OptionalChaining) {
    auto result = Ex12::divide(10, 2)
        .and_then([](double x) { return Ex12::sqrt(x); })
        .transform([](double x) { return x * 2; })
        .value_or(0.0);

    EXPECT_NEAR(result, 4.472, 0.001);
}

TEST(Ex12_TypeTechniques, TypeList) {
    using List = Ex12::TypeList<int, double, char>;
    EXPECT_EQ(Ex12::Length<List>::value, 3);

    using First = Ex12::Front<List>;
    EXPECT_TRUE((std::is_same_v<First, int>));
}

TEST(Ex12_TypeTechniques, TagDispatching) {
    std::vector<int> vec{3, 1, 4, 1, 5};
    Ex12::sort(vec, Ex12::FastTag{});
    // vec should be sorted
    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}
*/

// ============================================================================
// EXERCISE 13: Advanced STL & Ranges Tests
// ============================================================================

// Uncomment these tests after implementing Exercise 13

/*
TEST(Ex13_STLRanges, SumOfSquares) {
    std::vector<int> v1 = {1, 2, 3, 4};
    EXPECT_EQ(Ex13::sumOfSquares(v1), 30);  // 1 + 4 + 9 + 16

    std::vector<int> v2 = {5};
    EXPECT_EQ(Ex13::sumOfSquares(v2), 25);

    std::vector<int> empty;
    EXPECT_EQ(Ex13::sumOfSquares(empty), 0);
}

TEST(Ex13_STLRanges, RangeIterator) {
    std::vector<int> collected;
    for (int i : Ex13::Range(1, 6)) {
        collected.push_back(i);
    }
    EXPECT_EQ(collected, std::vector<int>({1, 2, 3, 4, 5}));

    collected.clear();
    for (int i : Ex13::Range(0, 0)) {
        collected.push_back(i);
    }
    EXPECT_TRUE(collected.empty());
}

TEST(Ex13_STLRanges, FibonacciIterator) {
    Ex13::FibonacciSequence fib;
    auto it = fib.begin();
    std::vector<int> first10;
    for (int i = 0; i < 10; ++i, ++it) {
        first10.push_back(*it);
    }
    EXPECT_EQ(first10, std::vector<int>({0, 1, 1, 2, 3, 5, 8, 13, 21, 34}));
}

TEST(Ex13_STLRanges, FilterIterator) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    auto isEven = [](int x) { return x % 2 == 0; };

    std::vector<int> evens;
    for (auto val : Ex13::FilterRange(v, isEven)) {
        evens.push_back(val);
    }
    EXPECT_EQ(evens, std::vector<int>({2, 4, 6, 8}));
}

TEST(Ex13_STLRanges, TransformAndFilter) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto result = Ex13::transformAndFilter(v);
    EXPECT_EQ(result, std::vector<int>({4, 16, 36, 64, 100}));
}

TEST(Ex13_STLRanges, ChunkView) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<std::vector<int>> chunks;

    for (auto chunk : Ex13::ChunkView(v, 3)) {
        std::vector<int> chunkVec(chunk.begin(), chunk.end());
        chunks.push_back(chunkVec);
    }

    EXPECT_EQ(chunks.size(), 3);
    EXPECT_EQ(chunks[0], std::vector<int>({1, 2, 3}));
    EXPECT_EQ(chunks[1], std::vector<int>({4, 5, 6}));
    EXPECT_EQ(chunks[2], std::vector<int>({7, 8}));
}

TEST(Ex13_STLRanges, ProcessArray) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    EXPECT_EQ(Ex13::processArray(v), 15);

    int arr[] = {1, 2, 3};
    EXPECT_EQ(Ex13::processArray(arr), 6);

    std::array<int, 4> stdArr = {10, 20, 30, 40};
    EXPECT_EQ(Ex13::processArray(stdArr), 100);
}

TEST(Ex13_STLRanges, PartitionAndSort) {
    std::vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4};
    auto mid = Ex13::partitionAndSort(v);

    // Check that all elements before mid are even and all after are odd
    for (auto it = v.begin(); it != mid; ++it) {
        EXPECT_EQ(*it % 2, 0);
    }
    for (auto it = mid; it != v.end(); ++it) {
        EXPECT_EQ(*it % 2, 1);
    }

    // Check that each partition is sorted
    EXPECT_TRUE(std::is_sorted(v.begin(), mid));
    EXPECT_TRUE(std::is_sorted(mid, v.end()));
}

TEST(Ex13_STLRanges, SortPeople) {
    std::vector<Ex13::Person> people = {
        {"Alice", 30}, {"Bob", 25}, {"Alice", 25}, {"Charlie", 30}
    };
    Ex13::sortPeople(people);

    EXPECT_EQ(people[0].name, "Alice");
    EXPECT_EQ(people[0].age, 25);
    EXPECT_EQ(people[1].name, "Bob");
    EXPECT_EQ(people[1].age, 25);
    EXPECT_EQ(people[2].name, "Alice");
    EXPECT_EQ(people[2].age, 30);
    EXPECT_EQ(people[3].name, "Charlie");
    EXPECT_EQ(people[3].age, 30);
}

TEST(Ex13_STLRanges, ZipIterator) {
    std::vector<int> keys = {1, 2, 3};
    std::vector<std::string> values = {"a", "b", "c"};

    std::vector<std::pair<int, std::string>> result;
    for (auto [k, v] : Ex13::zip(keys, values)) {
        result.emplace_back(k, v);
    }

    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], std::make_pair(1, std::string("a")));
    EXPECT_EQ(result[1], std::make_pair(2, std::string("b")));
    EXPECT_EQ(result[2], std::make_pair(3, std::string("c")));
}

TEST(Ex13_STLRanges, BuildPipeline) {
    std::vector<std::string> words = {"hi", "hello", "world", "a", "test", "data", "example"};
    auto result = Ex13::buildPipeline(words);

    EXPECT_LE(result.size(), 5);
    for (const auto& word : result) {
        EXPECT_GT(word.length(), 3);
        // Check if uppercase
        for (char c : word) {
            EXPECT_TRUE(std::isupper(c) || !std::isalpha(c));
        }
    }
}

TEST(Ex13_STLRanges, FindPattern) {
    std::vector<int> data = {1, 2, 3, 4, 5, 3, 4, 6};
    std::vector<int> pattern = {3, 4};

    auto it = Ex13::findPattern(data.begin(), data.end(), pattern.begin(), pattern.end());
    EXPECT_NE(it, data.end());
    EXPECT_EQ(*it, 3);
    EXPECT_EQ(std::distance(data.begin(), it), 2);
}

TEST(Ex13_STLRanges, SlidingWindowView) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> windows;

    for (auto window : Ex13::SlidingWindowView(v, 3)) {
        std::vector<int> windowVec(window.begin(), window.end());
        windows.push_back(windowVec);
    }

    EXPECT_EQ(windows.size(), 3);
    EXPECT_EQ(windows[0], std::vector<int>({1, 2, 3}));
    EXPECT_EQ(windows[1], std::vector<int>({2, 3, 4}));
    EXPECT_EQ(windows[2], std::vector<int>({3, 4, 5}));
}

TEST(Ex13_STLRanges, SetOperations) {
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {3, 4, 5, 6};

    auto u = Ex13::setUnion(a, b);
    EXPECT_EQ(u, std::vector<int>({1, 2, 3, 4, 5, 6}));

    auto i = Ex13::setIntersection(a, b);
    EXPECT_EQ(i, std::vector<int>({3, 4}));

    auto d = Ex13::setDifference(a, b);
    EXPECT_EQ(d, std::vector<int>({1, 2}));
}

TEST(Ex13_STLRanges, LazyGenerator) {
    auto gen = Ex13::Generator([n=0]() mutable { return n++; });

    std::vector<int> collected;
    int count = 0;
    for (int val : gen) {
        collected.push_back(val);
        if (++count >= 5) break;
    }

    EXPECT_EQ(collected, std::vector<int>({0, 1, 2, 3, 4}));
}
*/

// ============================================================================
// EXERCISE 14: Functional Programming Tests
// ============================================================================

// Uncomment these tests after implementing Exercise 14

/*
TEST(Ex14_Functional, Map) {
    std::vector<int> v = {1, 2, 3, 4};
    auto squared = Ex14::map(v, [](int x) { return x * x; });
    EXPECT_EQ(squared, std::vector<int>({1, 4, 9, 16}));
}

TEST(Ex14_Functional, Filter) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    auto evens = Ex14::filter(v, [](int x) { return x % 2 == 0; });
    EXPECT_EQ(evens, std::vector<int>({2, 4, 6}));
}

TEST(Ex14_Functional, Reduce) {
    std::vector<int> v = {1, 2, 3, 4};
    int sum = Ex14::reduce(v, 0, [](int acc, int x) { return acc + x; });
    EXPECT_EQ(sum, 10);

    int product = Ex14::reduce(v, 1, [](int acc, int x) { return acc * x; });
    EXPECT_EQ(product, 24);
}

TEST(Ex14_Functional, Compose) {
    auto addOne = [](int x) { return x + 1; };
    auto doubleIt = [](int x) { return x * 2; };
    auto f = Ex14::compose(addOne, doubleIt);

    EXPECT_EQ(f(5), 11);  // (5 * 2) + 1
}

TEST(Ex14_Functional, Curry) {
    auto add = [](int a, int b, int c) { return a + b + c; };
    auto curriedAdd = Ex14::curry(add);
    auto add5 = curriedAdd(5);
    auto add5and3 = add5(3);

    EXPECT_EQ(add5and3(2), 10);
}

TEST(Ex14_Functional, Partial) {
    auto add = [](int a, int b, int c) { return a + b + c; };
    auto add5and3 = Ex14::partial(add, 5, 3);

    EXPECT_EQ(add5and3(2), 10);
}

TEST(Ex14_Functional, OptionalMap) {
    std::optional<int> x = 42;
    auto result = Ex14::optionalMap(x, [](int n) { return n * 2; });
    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), 84);

    std::optional<int> empty;
    auto result2 = Ex14::optionalMap(empty, [](int n) { return n * 2; });
    EXPECT_FALSE(result2.has_value());
}

TEST(Ex14_Functional, OptionalFlatMap) {
    auto safeDivide = [](int a, int b) -> std::optional<int> {
        if (b == 0) return std::nullopt;
        return a / b;
    };

    std::optional<int> x = 42;
    auto result = Ex14::optionalFlatMap(x, [&](int n) { return safeDivide(n, 2); });
    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), 21);

    auto result2 = Ex14::optionalFlatMap(x, [&](int n) { return safeDivide(n, 0); });
    EXPECT_FALSE(result2.has_value());
}

TEST(Ex14_Functional, ResultType) {
    auto divide = [](int a, int b) -> Ex14::Result<int, std::string> {
        if (b == 0) return Ex14::Err(std::string("Division by zero"));
        return Ex14::Ok(a / b);
    };

    auto r1 = divide(10, 2);
    EXPECT_TRUE(r1.isOk());
    EXPECT_EQ(r1.value(), 5);

    auto r2 = divide(10, 0);
    EXPECT_TRUE(r2.isErr());
    EXPECT_EQ(r2.error(), "Division by zero");
}

TEST(Ex14_Functional, Functor) {
    std::vector<int> v = {1, 2, 3};
    auto doubled = Ex14::fmap(v, [](int x) { return x * 2; });
    EXPECT_EQ(doubled, std::vector<int>({2, 4, 6}));
}

TEST(Ex14_Functional, LazyEvaluation) {
    int callCount = 0;
    Ex14::Lazy<int> lazy([&callCount]() {
        callCount++;
        return 42;
    });

    EXPECT_EQ(callCount, 0);
    int x = lazy.value();
    EXPECT_EQ(callCount, 1);
    EXPECT_EQ(x, 42);

    int y = lazy.value();
    EXPECT_EQ(callCount, 1);  // Should not recompute
    EXPECT_EQ(y, 42);
}

TEST(Ex14_Functional, Memoization) {
    int callCount = 0;
    auto expensive = [&callCount](int x) {
        callCount++;
        return x * x;
    };

    auto memoized = Ex14::memoize(expensive);

    EXPECT_EQ(memoized(5), 25);
    EXPECT_EQ(callCount, 1);

    EXPECT_EQ(memoized(5), 25);
    EXPECT_EQ(callCount, 1);  // Should use cached value

    EXPECT_EQ(memoized(10), 100);
    EXPECT_EQ(callCount, 2);
}

TEST(Ex14_Functional, PipelineOperator) {
    auto addOne = [](int x) { return x + 1; };
    auto doubleIt = [](int x) { return x * 2; };

    int result = 5 | addOne | doubleIt;
    EXPECT_EQ(result, 12);  // (5 + 1) * 2
}

TEST(Ex14_Functional, ForEach) {
    std::vector<int> v = {1, 2, 3, 4};
    int sum = 0;
    Ex14::forEach(v, [&sum](int x) { sum += x; });
    EXPECT_EQ(sum, 10);
}

TEST(Ex14_Functional, Any) {
    std::vector<int> v = {1, 2, 3, 4};
    EXPECT_TRUE(Ex14::any(v, [](int x) { return x % 2 == 0; }));
    EXPECT_FALSE(Ex14::any(v, [](int x) { return x > 10; }));
}

TEST(Ex14_Functional, All) {
    std::vector<int> v = {2, 4, 6, 8};
    EXPECT_TRUE(Ex14::all(v, [](int x) { return x % 2 == 0; }));
    EXPECT_FALSE(Ex14::all(v, [](int x) { return x > 5; }));
}

TEST(Ex14_Functional, FlatMap) {
    std::vector<int> v = {1, 2, 3};
    auto duplicate = [](int x) { return std::vector<int>{x, x}; };
    auto result = Ex14::flatMap(v, duplicate);
    EXPECT_EQ(result, std::vector<int>({1, 1, 2, 2, 3, 3}));
}

TEST(Ex14_Functional, YCombinator) {
    auto fib = Ex14::Y([](auto self, int n) -> int {
        if (n <= 1) return n;
        return self(n - 1) + self(n - 2);
    });

    EXPECT_EQ(fib(0), 0);
    EXPECT_EQ(fib(1), 1);
    EXPECT_EQ(fib(10), 55);
}
*/

// ============================================================================
// EXERCISE 15: Performance Patterns Tests
// ============================================================================

// Uncomment these tests after implementing Exercise 15

/*
TEST(Ex15_Performance, ParticleSystemSoA) {
    Ex15::ParticleSystemSoA system(100);
    system.update(0.016f);
    // Just verify it compiles and runs without crashing
    SUCCEED();
}

TEST(Ex15_Performance, FalseSharingFix) {
    EXPECT_GE(sizeof(Ex15::PaddedCounter), 64);  // Should be at least cache line size
    EXPECT_GE(alignof(Ex15::PaddedCounter), 64);
}

TEST(Ex15_Performance, MatrixTranspose) {
    Ex15::Matrix m(10, 10);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            m.set(i, j, i * 10 + j);
        }
    }

    Ex15::transposeOptimized(m);
    EXPECT_EQ(m.get(0, 5), 50);
    EXPECT_EQ(m.get(5, 0), 5);
}

TEST(Ex15_Performance, BranchPrediction) {
    std::vector<int> data(1000);
    for (int i = 0; i < 1000; ++i) {
        data[i] = i;
    }

    auto result = Ex15::searchWithHints(data, 999);
    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), 999);
}

TEST(Ex15_Performance, MemoryPool) {
    Ex15::MemoryPool<int, 10> pool;

    int* p1 = pool.allocate();
    int* p2 = pool.allocate();

    *p1 = 42;
    *p2 = 100;

    EXPECT_EQ(*p1, 42);
    EXPECT_EQ(*p2, 100);

    pool.deallocate(p1);
    pool.deallocate(p2);
}

TEST(Ex15_Performance, StackAllocator) {
    Ex15::StackAllocator allocator(1024);

    void* p1 = allocator.allocate(100);
    void* p2 = allocator.allocate(200);

    EXPECT_NE(p1, nullptr);
    EXPECT_NE(p2, nullptr);

    allocator.reset();
}

TEST(Ex15_Performance, HotColdDataSeparation) {
    Ex15::GameObjectHot hot;
    hot.position[0] = 1.0f;
    hot.position[1] = 2.0f;
    hot.position[2] = 3.0f;

    Ex15::GameObjectCold cold;
    cold.name = "Player";
    cold.id = 42;

    EXPECT_EQ(cold.name, "Player");
    EXPECT_EQ(cold.id, 42);
}

TEST(Ex15_Performance, ObjectPool) {
    Ex15::ObjectPool<int> pool(10);

    int* obj1 = pool.acquire();
    int* obj2 = pool.acquire();

    *obj1 = 42;
    *obj2 = 100;

    pool.release(obj1);
    pool.release(obj2);

    int* obj3 = pool.acquire();
    EXPECT_NE(obj3, nullptr);
    pool.release(obj3);
}

TEST(Ex15_Performance, SmallStringOptimization) {
    Ex15::SmallString s1("short");
    EXPECT_EQ(s1.str(), "short");
    EXPECT_FALSE(s1.isHeapAllocated());

    Ex15::SmallString s2("this is a very long string that exceeds SSO buffer");
    EXPECT_TRUE(s2.isHeapAllocated());
}

TEST(Ex15_Performance, CopyOnWrite) {
    Ex15::CoWString s1("hello");
    Ex15::CoWString s2 = s1;

    // Should share buffer
    EXPECT_EQ(s1.useCount(), 2);
    EXPECT_EQ(s2.useCount(), 2);

    // Modify s2, should trigger copy
    s2.modify();
    EXPECT_EQ(s1.useCount(), 1);
    EXPECT_EQ(s2.useCount(), 1);
}

TEST(Ex15_Performance, FlatHashMap) {
    Ex15::FlatHashMap<int, std::string> map;

    map.insert(1, "one");
    map.insert(2, "two");
    map.insert(3, "three");

    auto* val1 = map.find(1);
    EXPECT_NE(val1, nullptr);
    EXPECT_EQ(*val1, "one");

    auto* val99 = map.find(99);
    EXPECT_EQ(val99, nullptr);
}

TEST(Ex15_Performance, SIMDAddition) {
    alignas(16) float a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    alignas(16) float b[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    alignas(16) float result[8];

    Ex15::addArraysSIMD(a, b, result, 8);

    for (int i = 0; i < 8; ++i) {
        EXPECT_FLOAT_EQ(result[i], 9.0f);
    }
}

TEST(Ex15_Performance, StructPacking) {
    EXPECT_LT(sizeof(Ex15::GoodStruct), sizeof(Ex15::BadStruct));
}

TEST(Ex15_Performance, BitPacking) {
    Ex15::PackedColor color;
    color.setRed(255);
    color.setGreen(128);
    color.setBlue(64);
    color.setAlpha(255);

    EXPECT_EQ(color.getRed(), 255);
    EXPECT_EQ(color.getGreen(), 128);
    EXPECT_EQ(color.getBlue(), 64);
    EXPECT_EQ(color.getAlpha(), 255);
}

TEST(Ex15_Performance, Benchmark) {
    auto result = Ex15::benchmark("test", []() {
        volatile int x = 0;
        for (int i = 0; i < 1000; ++i) {
            x += i;
        }
    }, 10);

    EXPECT_GT(result.avgTime, 0);
    EXPECT_GT(result.minTime, 0);
    EXPECT_LE(result.minTime, result.avgTime);
}

TEST(Ex15_Performance, CustomAllocator) {
    std::vector<int, Ex15::PoolAllocator<int>> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST(Ex15_Performance, ConstexprFactorial) {
    constexpr int f5 = Ex15::factorial(5);
    EXPECT_EQ(f5, 120);

    constexpr int f0 = Ex15::factorial(0);
    EXPECT_EQ(f0, 1);
}

TEST(Ex15_Performance, ConstexprPower) {
    constexpr int p1 = Ex15::power(2, 10);
    EXPECT_EQ(p1, 1024);

    constexpr int p2 = Ex15::power(5, 3);
    EXPECT_EQ(p2, 125);
}
*/

// ============================================================================
// EXERCISE 16: Move Semantics Tests
// ============================================================================

// Uncomment these tests after implementing Exercise 16

/*
TEST(Ex16_MoveSemantics, BasicMoveConstructor) {
    Ex16::Buffer b1(100);
    EXPECT_EQ(b1.size(), 100);

    Ex16::Buffer b2 = std::move(b1);
    EXPECT_EQ(b2.size(), 100);
    EXPECT_EQ(b1.size(), 0);  // Moved-from state
}

TEST(Ex16_MoveSemantics, MoveAssignment) {
    Ex16::Buffer b1(100);
    Ex16::Buffer b2(50);

    b2 = std::move(b1);
    EXPECT_EQ(b2.size(), 100);
    EXPECT_EQ(b1.size(), 0);
}

TEST(Ex16_MoveSemantics, RuleOfFive) {
    Ex16::String s1("hello");
    EXPECT_EQ(s1.c_str(), std::string("hello"));

    // Copy constructor
    Ex16::String s2 = s1;
    EXPECT_EQ(s2.c_str(), std::string("hello"));
    EXPECT_EQ(s1.c_str(), std::string("hello"));

    // Move constructor
    Ex16::String s3 = std::move(s1);
    EXPECT_EQ(s3.c_str(), std::string("hello"));

    // Copy assignment
    Ex16::String s4("temp");
    s4 = s2;
    EXPECT_EQ(s4.c_str(), std::string("hello"));

    // Move assignment
    Ex16::String s5("temp");
    s5 = std::move(s2);
    EXPECT_EQ(s5.c_str(), std::string("hello"));
}

TEST(Ex16_MoveSemantics, MoveOnlyType) {
    Ex16::FileHandle file1("test.txt");

    // Move constructor
    Ex16::FileHandle file2 = std::move(file1);
    EXPECT_TRUE(file2.isValid());
    EXPECT_FALSE(file1.isValid());

    // Move assignment
    Ex16::FileHandle file3("other.txt");
    file3 = std::move(file2);
    EXPECT_TRUE(file3.isValid());
    EXPECT_FALSE(file2.isValid());

    // Should be able to store in vector
    std::vector<Ex16::FileHandle> files;
    files.push_back(Ex16::FileHandle("file.txt"));
    EXPECT_EQ(files.size(), 1);
}

TEST(Ex16_MoveSemantics, PerfectForwarding) {
    auto ptr1 = Ex16::makeUnique<std::string>(5, 'x');
    EXPECT_EQ(*ptr1, "xxxxx");

    auto ptr2 = Ex16::makeUnique<std::vector<int>>(3, 42);
    EXPECT_EQ(ptr2->size(), 3);
    EXPECT_EQ((*ptr2)[0], 42);
}

TEST(Ex16_MoveSemantics, UniversalReferences) {
    int x = 42;
    Ex16::processValue(x);  // Lvalue
    Ex16::processValue(42);  // Rvalue
    Ex16::processValue(std::move(x));  // Rvalue

    // Just verify it compiles
    SUCCEED();
}

TEST(Ex16_MoveSemantics, MyMove) {
    std::string s1 = "hello";
    std::string s2 = Ex16::myMove(s1);

    EXPECT_EQ(s2, "hello");
    // s1 is in valid but unspecified state
}

TEST(Ex16_MoveSemantics, RVO) {
    auto w1 = Ex16::createWidget();
    // Should use RVO, no copy or move

    auto w2 = Ex16::createWidgetNRVO();
    // Should use NRVO

    SUCCEED();
}

TEST(Ex16_MoveSemantics, ConditionalNoexcept) {
    // Verify that move constructor is conditionally noexcept
    struct NoThrowMove {
        NoThrowMove() = default;
        NoThrowMove(NoThrowMove&&) noexcept = default;
    };

    struct ThrowMove {
        ThrowMove() = default;
        ThrowMove(ThrowMove&&) {}  // Not noexcept
    };

    EXPECT_TRUE(std::is_nothrow_move_constructible_v<Ex16::Container<NoThrowMove>>);
    EXPECT_FALSE(std::is_nothrow_move_constructible_v<Ex16::Container<ThrowMove>>);
}

TEST(Ex16_MoveSemantics, MoveIfNoexcept) {
    Ex16::MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST(Ex16_MoveSemantics, BuilderPattern) {
    auto widget = Ex16::WidgetBuilder()
        .setX(10)
        .setY(20)
        .setWidth(100)
        .setHeight(50)
        .build();

    EXPECT_EQ(widget->getX(), 10);
    EXPECT_EQ(widget->getY(), 20);
}

TEST(Ex16_MoveSemantics, RefQualifiers) {
    Ex16::StringWithRefs s1("hello");
    const char* data1 = s1.data();  // Lvalue-qualified
    EXPECT_NE(data1, nullptr);

    char* data2 = Ex16::StringWithRefs("temp").data();  // Rvalue-qualified
    EXPECT_NE(data2, nullptr);
}

TEST(Ex16_MoveSemantics, MyExchange) {
    int x = 5;
    int old = Ex16::myExchange(x, 10);

    EXPECT_EQ(old, 5);
    EXPECT_EQ(x, 10);
}

TEST(Ex16_MoveSemantics, SimpleVectorMove) {
    Ex16::SimpleVector<int> v1 = {1, 2, 3, 4, 5};
    EXPECT_EQ(v1.size(), 5);

    Ex16::SimpleVector<int> v2 = std::move(v1);
    EXPECT_EQ(v2.size(), 5);
    EXPECT_EQ(v1.size(), 0);

    Ex16::SimpleVector<int> v3;
    v3 = std::move(v2);
    EXPECT_EQ(v3.size(), 5);
    EXPECT_EQ(v2.size(), 0);
}

TEST(Ex16_MoveSemantics, VariadicForwarding) {
    Ex16::ConstructInPlace<std::string> cip;
    cip.emplace(5, 'x');
    EXPECT_EQ(cip.get(), "xxxxx");

    Ex16::ConstructInPlace<std::vector<int>> cip2;
    cip2.emplace(3, 42);
    EXPECT_EQ(cip2.get().size(), 3);
}

TEST(Ex16_MoveSemantics, Inheritance) {
    Ex16::Derived d1("base", "derived");

    Ex16::Derived d2 = std::move(d1);
    EXPECT_EQ(d2.getBaseData(), "base");
    EXPECT_EQ(d2.getDerivedData(), "derived");
}

TEST(Ex16_MoveSemantics, MovedFromDetection) {
    Ex16::DebugWidget w1;
    EXPECT_FALSE(w1.isMovedFrom());

    Ex16::DebugWidget w2 = std::move(w1);
    EXPECT_TRUE(w1.isMovedFrom());
    EXPECT_FALSE(w2.isMovedFrom());
}

TEST(Ex16_MoveSemantics, UniquePtr) {
    Ex16::UniquePtr<int> ptr1 = Ex16::makeUnique<int>(42);
    EXPECT_EQ(*ptr1, 42);

    Ex16::UniquePtr<int> ptr2 = std::move(ptr1);
    EXPECT_EQ(*ptr2, 42);
    EXPECT_EQ(ptr1.get(), nullptr);

    ptr2.reset();
    EXPECT_EQ(ptr2.get(), nullptr);
}

TEST(Ex16_MoveSemantics, GuaranteedCopyElision) {
    // C++17 guaranteed copy elision
    Ex16::CopyElisionWidget w = Ex16::CopyElisionWidget();

    Ex16::takesWidget(Ex16::CopyElisionWidget());

    SUCCEED();
}
*/

// ============================================================================
// Main function
// ============================================================================

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
