#pragma once
#include <iostream>
#include <type_traits>
#include <utility>
#include <memory>

/**
 * Exercise 07: Advanced Template Techniques
 *
 * Learning objectives:
 * - Expression templates
 * - Policy-based design
 * - CRTP (Curiously Recurring Template Pattern)
 * - Tag dispatching
 * - Template metaprogramming
 */

namespace Ex07 {

// ============================================================================
// EXERCISE 7.1: CRTP - Basic Pattern
// ============================================================================
// TODO: Implement a CRTP base class 'Comparable' that provides comparison operators
// Requirements:
// - Template parameter is the derived class
// - Implement operator!=, >, <=, >= using operator< and operator==
// - Derived class must provide operator< and operator==
//
// Then create a 'Number' class that derives from Comparable
//
// Example usage:
//   Number a{5}, b{10};
//   bool x = a < b;   // provided by Number
//   bool y = a > b;   // provided by Comparable via CRTP
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 7.2: Policy-Based Design
// ============================================================================
// TODO: Implement a 'SmartPtr' class using policies
// Requirements:
// - Template parameters: T (type) and DeletionPolicy
// - DeletionPolicy can be: DefaultDelete, ArrayDelete, NoDelete
// - Use the policy in the destructor
// - Implement basic smart pointer operations (get, release, operator*)
//
// Example usage:
//   SmartPtr<int, DefaultDelete> p{new int{5}};
//   SmartPtr<int[], ArrayDelete> arr{new int[10]};
//
// YOUR CODE HERE:
// Policies:
struct DefaultDelete {
    template<typename T>
    static void destroy(T* ptr) { delete ptr; }
};

struct ArrayDelete {
    template<typename T>
    static void destroy(T* ptr) { delete[] ptr; }
};

struct NoDelete {
    template<typename T>
    static void destroy(T*) { /* do nothing */ }
};

// SmartPtr class:




// ============================================================================
// EXERCISE 7.3: Tag Dispatching
// ============================================================================
// TODO: Implement 'advance' for iterators using tag dispatching
// Requirements:
// - Create implementation functions for different iterator tags
// - advanceImpl for random_access_iterator_tag: use it += n
// - advanceImpl for input_iterator_tag: use loop
// - Main advance function dispatches to correct version
//
// Example usage:
//   auto it = vec.begin();
//   advance(it, 5);  // dispatches based on iterator category
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 7.4: Expression Templates (Basic)
// ============================================================================
// TODO: Implement basic expression templates for lazy vector addition
// Requirements:
// - Create 'VecExpression' template for expressions
// - Create 'VecSum' to represent sum of two vectors
// - Overload operator+ to return expression, not evaluated result
// - Evaluation happens in assignment
//
// Example usage:
//   Vec a{1,2,3}, b{4,5,6}, c{7,8,9};
//   Vec result = a + b + c;  // evaluates once, not twice
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 7.5: Compile-Time Fibonacci
// ============================================================================
// TODO: Implement compile-time Fibonacci using template metaprogramming
// Requirements:
// - Create Fibonacci<N> struct with static const value
// - Use template recursion
// - Base cases: Fibonacci<0> = 0, Fibonacci<1> = 1
// - Recursive case: Fibonacci<N> = Fibonacci<N-1> + Fibonacci<N-2>
//
// Example usage:
//   constexpr auto fib5 = Fibonacci<5>::value;  // 5 at compile time
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 7.6: Type List Manipulation
// ============================================================================
// TODO: Implement a simple type list and operations
// Requirements:
// - TypeList<Types...> to hold a list of types
// - Length<TypeList> to get length
// - Front<TypeList> to get first type
// - PushFront<T, TypeList> to add type at front
//
// Example usage:
//   using List = TypeList<int, double, char>;
//   using Len = Length<List>;  // Len::value == 3
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 7.7: Mixin Classes
// ============================================================================
// TODO: Implement mixin classes that can be combined
// Requirements:
// - Create CountableMixin: adds instance counting
// - Create PrintableMixin: adds print() method
// - Create a class that uses both mixins
// - Use CRTP to make mixins work with derived class
//
// Example usage:
//   class MyClass : public CountableMixin<MyClass>,
//                   public PrintableMixin<MyClass> { };
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 7.8: Static Polymorphism vs Virtual
// ============================================================================
// TODO: Implement the same interface using both approaches
// Requirements:
// - Create ShapeBase with virtual draw()
// - Create Circle and Square deriving from ShapeBase
// - Create ShapeCRTP using CRTP instead of virtual
// - Create CircleCRTP and SquareCRTP using CRTP
// - Implement drawShape() for both approaches
//
// Compare performance implications (virtual dispatch vs compile-time)
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 7.9: Compile-Time Prime Checking
// ============================================================================
// TODO: Implement compile-time prime number checking
// Requirements:
// - IsPrime<N> struct with bool value
// - Use template metaprogramming
// - Helper: IsDivisible<N, D> checks if N % D == 0
// - Check divisors from 2 to sqrt(N)
//
// Example usage:
//   constexpr bool is7Prime = IsPrime<7>::value;  // true
//   constexpr bool is9Prime = IsPrime<9>::value;  // false
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 7.10: Member Detector Idiom
// ============================================================================
// TODO: Implement a member detector using template metaprogramming
// Requirements:
// - Create HAS_MEMBER macro that generates a trait
// - Use SFINAE with sizeof trick or void_t
// - Detect both member variables and member functions
//
// Example:
//   HAS_MEMBER(size)
//   // Creates has_size<T> trait
//   bool x = has_size<std::vector<int>>::value;  // true
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 7.11: Compile-Time String
// ============================================================================
// TODO: Implement a compile-time string using non-type template parameters
// Requirements:
// - Template on char array
// - Length() constexpr method
// - At(N) constexpr method to access character
// - C++20: Use template <char... Chars> approach
//
// Example usage:
//   constexpr auto str = CompileTimeString<'h', 'i'>{};
//   constexpr auto len = str.length();  // 2
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 7.12: Type Traits Implementation
// ============================================================================
// TODO: Implement your own type traits
// Requirements:
// - MyIsPointer<T>: detects pointer types
// - MyRemoveConst<T>: removes const qualifier
// - MyIsArray<T>: detects array types
// - Use template specialization
//
// Example usage:
//   bool x = MyIsPointer<int*>::value;    // true
//   using T = MyRemoveConst<const int>::type;  // int
//
// YOUR CODE HERE:




} // namespace Ex07
