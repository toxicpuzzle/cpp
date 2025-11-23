# C++ Template Mastery & Design Patterns

A comprehensive series of exercises designed to master C++ templates, idioms, design patterns, and advanced metaprogramming techniques.

## 📚 Overview

This exercise set covers:

**Template Techniques:**
- ✅ Basic function and class templates
- ✅ Template specialization
- ✅ Variadic templates
- ✅ SFINAE techniques
- ✅ C++20 Concepts
- ✅ Advanced patterns (CRTP, Expression Templates, etc.)

**C++ Patterns & Idioms:**
- ✅ X Macros (preprocessor metaprogramming)
- ✅ PIMPL (Pointer to Implementation)
- ✅ RAII, Rule of Three/Five, Copy-and-Swap
- ✅ Design Patterns (Gang of Four with modern C++)
- ✅ Type Erasure, Strong Types, Phantom Types

## 🎯 Learning Path

### Exercise 01: Function Templates (Basics)
**File:** `01_function_templates.hpp`

Learn the fundamentals of function templates:
- Basic template syntax and type deduction
- Multiple template parameters
- Non-type template parameters
- Return type deduction with `auto`
- Template overloading

**Key Concepts:**
- `template<typename T>`
- Type deduction vs explicit specification
- Template parameter defaults
- Working with containers

**Exercises:** 8 progressively challenging problems

---

### Exercise 02: Class Templates
**File:** `02_class_templates.hpp`

Master class templates by building your own containers:
- Fixed-size and dynamic arrays
- Custom pair and tuple implementations
- Stack data structure
- Member function templates
- Static members in templates
- Nested template classes

**Build Your Own:**
- `FixedArray<T, N>` - compile-time sized array
- `DynamicArray<T>` - dynamic vector-like container
- `Stack<T, N>` - LIFO container
- `SmallVector<T>` - initializer list support

**Exercises:** 8 hands-on implementations

---

### Exercise 03: Template Specialization
**File:** `03_specialization.hpp`

Learn to specialize templates for specific types:
- Full function template specialization
- Full class template specialization
- Partial specialization
- Specialization for optimization
- Pointer and reference specializations

**Real-World Applications:**
- Optimized `strcmp` for C-strings
- Bit-packed `bool` storage
- Type detection (`TypeInfo<T>`)
- Default value factories
- memcpy optimization for POD types

**Exercises:** 8 specialization patterns

---

### Exercise 04: Variadic Templates
**File:** `04_variadic_templates.hpp`

Handle arbitrary numbers of template arguments:
- Parameter packs and pack expansion
- Recursive template techniques
- C++17 fold expressions
- Perfect forwarding
- Index sequences

**Create Utilities:**
- `print(args...)` - variadic printer
- `sum(args...)` - fold expression sum
- `maximum(args...)` - recursive max finder
- `forEach(func, args...)` - apply function to all

**Exercises:** 12 variadic patterns

---

### Exercise 05: SFINAE
**File:** `05_sfinae.hpp`

Substitution Failure Is Not An Error - conditional compilation:
- `std::enable_if` patterns
- Type trait detection
- Member function detection
- Iterator category detection
- `std::void_t` idiom

**Advanced Techniques:**
- Overload sets based on type properties
- Compile-time type selection
- Custom trait implementation
- Return type SFINAE

**Exercises:** 10 SFINAE techniques

---

### Exercise 06: C++20 Concepts
**File:** `06_concepts.hpp`

Modern, readable template constraints:
- Basic concept definition
- Concept composition
- Standard library concepts
- Requires clauses
- Concept subsumption

**Define Concepts:**
- `Numeric` - arithmetic types
- `Comparable` - types with `operator<`
- `Container` - types with begin/end/size
- `Printable` - types with `operator<<`

**Note:** Requires C++20 compiler support

**Exercises:** 12 concept patterns

---

### Exercise 07: Advanced Techniques
**File:** `07_advanced.hpp`

Master advanced template metaprogramming:
- CRTP (Curiously Recurring Template Pattern)
- Policy-based design
- Tag dispatching
- Expression templates
- Compile-time computation
- Type list manipulation

**Advanced Patterns:**
- `Comparable<Derived>` - CRTP mixin
- `SmartPtr<T, Policy>` - policy-based design
- `Fibonacci<N>` - compile-time recursion
- `IsPrime<N>` - compile-time prime checking
- Expression templates for lazy evaluation

**Exercises:** 12 advanced techniques

---

### Exercise 08: X Macros Pattern
**File:** `08_x_macros.hpp`

Master the X Macros preprocessor pattern for code generation:
- Generate enums with string conversion
- Create dispatch tables
- Build state machines
- Handle multi-argument macros
- Combine with modern C++ features

**Real-World Applications:**
- Error code systems with automatic stringification
- Command pattern with switch generation
- Configuration parameter management
- Bit flag systems
- Test case generation

**Learn to Build:**
- `Color` enum with automatic `colorToString()`
- Error code system with messages
- Function dispatch tables
- Reflection-like systems
- State machine validators

**Exercises:** 12 X Macro patterns

---

### Exercise 09: PIMPL Idiom
**File:** `09_pimpl.hpp`

Implement Pointer to Implementation for compilation firewalls:
- Reduce compilation dependencies
- Hide implementation details
- Maintain ABI stability
- Use unique_ptr and shared_ptr appropriately
- Handle copyability correctly

**PIMPL Variations:**
- Basic PIMPL with `unique_ptr`
- Copyable PIMPL (deep copy)
- Shared PIMPL with copy-on-write
- Thread-safe PIMPL
- Platform abstraction layer

**Benefits:**
- Faster compilation for clients
- Binary compatibility
- True information hiding
- Flexibility to change implementation

**Exercises:** 13 PIMPL implementations

---

### Exercise 10: Essential C++ Idioms
**File:** `10_cpp_idioms.hpp`

Master fundamental C++ idioms and best practices:
- RAII (Resource Acquisition Is Initialization)
- Rule of Zero/Three/Five
- Copy-and-Swap
- Named Parameter Idiom
- NVI (Non-Virtual Interface)
- Strong Types
- Scope Guard

**Critical Concepts:**
- When to define special member functions
- Exception-safe assignment
- Fluent interfaces
- Preventing type confusion
- Automatic cleanup patterns
- Encapsulation techniques

**Build Your Skills:**
- `FileHandle` - RAII wrapper
- `Buffer` - Rule of Five
- `String` - Copy-and-Swap
- `StrongType<T, Tag>` - type safety
- `ScopeGuard` - cleanup automation

**Exercises:** 15 essential idioms

---

### Exercise 11: Design Patterns in Modern C++
**File:** `11_design_patterns.hpp`

Classic Gang of Four patterns with modern C++ features:
- Smart pointers (unique_ptr, shared_ptr, weak_ptr)
- Lambda functions and std::function
- Move semantics
- Type erasure
- Template-based patterns

**Patterns Covered:**
- **Creational:** Singleton, Factory, Abstract Factory, Builder, Prototype
- **Behavioral:** Observer, Strategy, Command, Visitor, Template Method, State, Chain of Responsibility
- **Structural:** Decorator, Adapter
- **Modern:** Type Erasure, Monostate

**Modern Approaches:**
- Thread-safe Singleton with magic statics
- Factory returning `unique_ptr`
- Observer with `weak_ptr` to avoid cycles
- Strategy with `std::function`
- Type erasure like `std::any`

**Exercises:** 16 design patterns

---

### Exercise 12: Advanced Type Techniques
**File:** `12_type_techniques.hpp`

Advanced type-level programming and compile-time techniques:
- Type erasure from scratch
- Strong type wrappers
- Phantom types for state tracking
- std::variant and std::optional patterns
- Type list metaprogramming
- Policy-based design

**Advanced Topics:**
- Implementing `std::any` and `std::function`
- Type-safe units (Meters, Seconds)
- Compile-time state machines
- Result<T, E> type
- Visitor patterns for variants
- Empty Base Optimization

**Type-Level Programming:**
- `TypeList<Ts...>` manipulation
- Trait classes
- Tag dispatching
- Opaque typedefs
- Recursive variants

**Exercises:** 17 type techniques

---

### Exercise 13: Advanced STL & Ranges (C++20)
**File:** `13_stl_ranges.hpp`

Master STL algorithms and modern C++20 ranges:
- Custom iterator implementation
- Range-based algorithms
- Lazy evaluation with views
- std::span for array views
- Composable range operations
- Iterator categories and traits

**Build Your Skills:**
- `RangeIterator` - generate number sequences
- `FibonacciIterator` - lazy Fibonacci generation
- `FilterIterator` - conditional iteration
- `ZipIterator` - iterate multiple ranges together
- Pipeline composition with views

**Advanced Topics:**
- Custom range adapters
- Sliding window views
- Set operations with ranges
- Multi-key sorting
- Generator patterns

**Note:** Requires C++20 for ranges support

**Exercises:** 15 range and algorithm patterns

---

### Exercise 14: Functional Programming in C++
**File:** `14_functional_programming.hpp`

Apply functional programming paradigms in C++:
- Higher-order functions (map, filter, reduce)
- Function composition and currying
- Monads: Optional, Result, State
- Lazy evaluation
- Lambda expressions and closures
- Pure functions and immutability

**Functional Patterns:**
- `map`, `filter`, `reduce` - collection transformations
- `compose` - function composition
- `curry` - partial application
- `Result<T, E>` - railway-oriented programming
- `Lazy<T>` - deferred computation
- `memoize` - automatic caching

**Advanced Techniques:**
- Monadic operations (flatMap/bind)
- Applicative functors
- Y combinator for recursion
- Transducers for efficient composition
- Pipeline operators
- Zipper data structures

**Exercises:** 18 functional patterns

---

### Exercise 15: Cache-Friendly & Performance Patterns
**File:** `15_performance_patterns.hpp`

Optimize code for modern CPU architectures:
- CPU cache hierarchy understanding
- Data-oriented design (DoD)
- Memory layout optimization
- False sharing prevention
- Branch prediction hints
- SIMD concepts

**Performance Techniques:**
- AoS vs SoA (Array of Structures vs Structure of Arrays)
- Cache line awareness and padding
- Memory pool allocators
- Stack/linear allocators
- Hot/cold data separation
- Object pool pattern

**Advanced Optimizations:**
- Small string optimization (SSO)
- Copy-on-write (CoW)
- Bit packing for compact data
- Custom STL allocators
- Compile-time computation
- Memory bandwidth testing

**Exercises:** 18 performance patterns

---

### Exercise 16: Modern Move Semantics Deep Dive
**File:** `16_move_semantics.hpp`

Master C++11/14/17 move semantics and perfect forwarding:
- Rvalue references and std::move
- Move constructors and move assignment
- Perfect forwarding with std::forward
- Universal references (forwarding references)
- Copy elision and RVO
- noexcept and move operations

**Essential Skills:**
- Rule of Five implementation
- Move-only types (unique resources)
- std::move vs std::forward
- Ref-qualifiers (& and &&)
- Conditional noexcept
- Exception safety with moves

**Advanced Topics:**
- Reference collapsing rules
- Return value optimization (RVO, NRVO)
- Guaranteed copy elision (C++17)
- Moving from *this
- Moved-from state detection
- Move semantics with inheritance

**Exercises:** 18 move semantics patterns

---

## 🚀 Getting Started

### Prerequisites
- C++17 or later compiler (C++20 for concepts)
- CMake 3.14+
- GoogleTest (automatically fetched)

### Build Instructions

1. **Configure the build:**
   ```bash
   cd /home/user/cpp/template_exercises
   cmake -B build
   ```

2. **Build the tests:**
   ```bash
   cmake --build build
   ```

3. **Run all tests:**
   ```bash
   ./build/tests/template_test
   ```

4. **Run specific test suite:**
   ```bash
   ./build/tests/template_test --gtest_filter=Ex01*
   ```

---

## 📝 How to Complete Exercises

### Step-by-Step Workflow

1. **Open an exercise file** (e.g., `01_function_templates.hpp`)

2. **Read the exercise description and requirements**
   - Each exercise has detailed comments
   - Usage examples are provided
   - Requirements are clearly specified

3. **Implement the solution** where it says `YOUR CODE HERE:`

4. **Open the test file** (`tests/template_exercises_test.cc`)

5. **Uncomment the include** for your exercise:
   ```cpp
   #include "../01_function_templates.hpp"
   ```

6. **Uncomment the corresponding tests:**
   ```cpp
   TEST(Ex01_FunctionTemplates, MyMax) {
       EXPECT_EQ(Ex01::myMax(5, 10), 10);
       // ...
   }
   ```

7. **Build and run tests:**
   ```bash
   cmake --build build
   ./build/tests/template_test
   ```

8. **Fix any compilation errors or test failures**

9. **Move to the next exercise**

---

## 💡 Tips for Success

### Template Debugging
- **Compiler errors can be verbose** - look for the actual error message buried in the output
- **Use `static_assert`** to test compile-time conditions
- **Break complex templates** into smaller helper templates
- **Test incrementally** - don't write everything at once

### Best Practices
- **Follow the existing code style:**
  - `m_` prefix for member variables
  - camelCase for methods
  - Clear, descriptive names
  - Comments for complex logic

- **Use modern C++ features:**
  - Structured bindings: `auto [a, b] = pair;`
  - `if constexpr` for compile-time branches
  - Range-based for loops
  - `auto` for type deduction

### Testing Strategy
1. Start with simple test cases
2. Test edge cases (empty, zero, null)
3. Test with different types
4. Verify both success and failure cases

---

## 🎓 Learning Resources

### Concepts to Master

**Exercise 01-02:**
- Template syntax and instantiation
- Type deduction rules
- Non-type template parameters

**Exercise 03:**
- Specialization rules and precedence
- Partial vs full specialization
- When to use specialization

**Exercise 04:**
- Parameter pack expansion
- Fold expressions
- Perfect forwarding with `std::forward`

**Exercise 05:**
- SFINAE principle
- `std::enable_if` patterns
- Type traits library
- `decltype` and `declval`

**Exercise 06:**
- Concepts vs SFINAE
- Requires clauses
- Concept subsumption rules

**Exercise 07:**
- CRTP pattern and static polymorphism
- Template metaprogramming
- Compile-time vs runtime decisions

---

## 🔍 Troubleshooting

### Common Issues

**Build fails with "C++20 required":**
```bash
# Check your CMakeLists.txt has:
set(CMAKE_CXX_STANDARD 20)
```

**Tests don't run:**
```bash
# Make sure you've uncommented the include and test cases
# Rebuild after changes:
cmake --build build
```

**Linker errors with static members:**
```cpp
// Don't forget to define static members outside the class:
template<typename T>
size_t Counter<T>::s_count = 0;
```

**Template errors are hard to read:**
- Use `c++filt` to demangle names
- Focus on the first error
- Use `-ftemplate-backtrace-limit=0` for full trace

---

## 📊 Progress Tracking

Track your progress through the exercises:

**Template Techniques (Exercises 01-07):**
- [ ] Exercise 01: Function Templates (8/8)
- [ ] Exercise 02: Class Templates (8/8)
- [ ] Exercise 03: Specialization (8/8)
- [ ] Exercise 04: Variadic Templates (12/12)
- [ ] Exercise 05: SFINAE (10/10)
- [ ] Exercise 06: Concepts (12/12) ⚠️ Requires C++20
- [ ] Exercise 07: Advanced Templates (12/12)

**C++ Patterns & Idioms (Exercises 08-12):**
- [ ] Exercise 08: X Macros Pattern (12/12)
- [ ] Exercise 09: PIMPL Idiom (13/13)
- [ ] Exercise 10: Essential C++ Idioms (15/15)
- [ ] Exercise 11: Design Patterns (16/16)
- [ ] Exercise 12: Advanced Type Techniques (17/17)

**Modern C++ Features (Exercises 13-16):**
- [ ] Exercise 13: Advanced STL & Ranges (15/15) ⚠️ Requires C++20
- [ ] Exercise 14: Functional Programming (18/18)
- [ ] Exercise 15: Cache-Friendly & Performance Patterns (18/18)
- [ ] Exercise 16: Modern Move Semantics Deep Dive (18/18)

**Total:** 212 exercises across 16 modules

---

## 🎯 Challenge Yourself

After completing the exercises:

1. **Extend your solutions:**
   - Add more functionality
   - Handle edge cases
   - Optimize performance

2. **Combine techniques:**
   - Use SFINAE with variadic templates
   - Apply concepts to CRTP
   - Create expression templates with concepts

3. **Real-world applications:**
   - Enhance your `libalg` matrix library with templates
   - Add template-based optimizations to thread pool
   - Create generic algorithms for your neural network

4. **Performance analysis:**
   - Compare template metaprogramming vs runtime
   - Benchmark specialized vs generic code
   - Analyze binary size impact

---

## 🤝 Integration with Existing Code

These exercises complement your existing projects:

**Linear Algebra Library (`libalg/`):**
- Apply template techniques to `Matrix` class
- Use concepts for type constraints
- Add expression templates for lazy evaluation

**Thread Pool:**
- Template the job type
- Use perfect forwarding for job arguments
- Apply SFINAE for callable detection

**Neural Network:**
- Template-based layer types
- Compile-time network architecture
- Generic activation functions

---

## 📚 References

**Templates & Metaprogramming:**
- [cppreference.com - Templates](https://en.cppreference.com/w/cpp/language/templates)
- [C++ Templates: The Complete Guide](https://www.josuttis.com/tmplbook/)
- [C++20 Concepts](https://en.cppreference.com/w/cpp/language/constraints)
- [SFINAE and enable_if](https://en.cppreference.com/w/cpp/types/enable_if)
- [Template Metaprogramming](https://en.wikibooks.org/wiki/C%2B%2B_Programming/Templates/Template_Meta-Programming)

**Design Patterns:**
- [Design Patterns: Elements of Reusable Object-Oriented Software](https://en.wikipedia.org/wiki/Design_Patterns) (Gang of Four)
- [Modern C++ Design](https://erdani.com/index.php/books/modern-c-design/) by Andrei Alexandrescu
- [C++ Patterns](https://cpppatterns.com/)

**Idioms:**
- [More C++ Idioms](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms)
- [X Macros](https://en.wikipedia.org/wiki/X_Macro)
- [PIMPL Idiom](https://cpppatterns.com/patterns/pimpl.html)

---

## 🎉 Completion

Once you've completed all exercises, you'll have mastered:
- Writing generic, reusable code with templates
- Compile-time computation and optimization
- Advanced C++ template techniques (SFINAE, concepts, metaprogramming)
- Modern C++17/20 features (ranges, views, concepts)
- Essential C++ idioms (RAII, Rule of Five, Copy-and-Swap)
- Classic design patterns with modern C++ (smart pointers, lambdas)
- Advanced type techniques (type erasure, strong types, phantom types)
- PIMPL idiom for compilation firewalls
- X Macros for code generation
- STL algorithms and custom iterator implementation
- C++20 ranges and lazy evaluation with views
- Functional programming patterns (map, filter, reduce, monads)
- Cache-friendly code and data-oriented design
- Performance optimization techniques
- Move semantics and perfect forwarding mastery

**Next Steps:**
- Apply these techniques to real projects
- Refactor existing code using learned patterns
- Explore template libraries (Boost, Eigen, Ranges-v3)
- Contribute to open-source C++ projects
- Share knowledge and mentor others
- Read advanced C++ books (Meyers, Sutter, Alexandrescu)
- Attend C++ conferences (CppCon, Meeting C++, C++Now)

---

Happy templating! 🚀
