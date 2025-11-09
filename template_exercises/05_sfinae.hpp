#pragma once
#include <iostream>
#include <type_traits>
#include <vector>
#include <iterator>

/**
 * Exercise 05: SFINAE (Substitution Failure Is Not An Error)
 *
 * Learning objectives:
 * - Understand SFINAE principle
 * - Use std::enable_if for conditional compilation
 * - Detect type properties with type traits
 * - Create overload sets based on type properties
 */

namespace Ex05 {

// ============================================================================
// EXERCISE 5.1: Basic enable_if - Return Type
// ============================================================================
// TODO: Implement two 'process' function overloads using enable_if
// Requirements:
// - First overload: enabled for integral types, returns value * 2
// - Second overload: enabled for floating point types, returns value / 2
// - Use std::enable_if_t in return type
// - Use std::is_integral and std::is_floating_point
//
// Example usage:
//   auto a = process(10);    // integral: returns 20
//   auto b = process(10.0);  // floating: returns 5.0
//
// YOUR CODE HERE:
// Integral version:



// Floating point version:




// ============================================================================
// EXERCISE 5.2: enable_if as Template Parameter
// ============================================================================
// TODO: Implement 'stringify' with enable_if as template parameter
// Requirements:
// - First overload: for arithmetic types, use std::to_string
// - Second overload: for types with operator<<, use stringstream
// - Use typename = std::enable_if_t<...> as template parameter
//
// Example usage:
//   auto s1 = stringify(42);      // "42"
//   auto s2 = stringify(3.14);    // "3.14"
//
// YOUR CODE HERE:
// Arithmetic version:



// Non-arithmetic version (this is tricky, you can skip the implementation):



// ============================================================================
// EXERCISE 5.3: Detect Member Function
// ============================================================================
// TODO: Create a trait to detect if a type has a 'size()' member function
// Requirements:
// - Implement has_size_method<T> trait using SFINAE
// - Use decltype and std::declval
// - Should have a static constexpr bool value member
//
// Then implement 'getSize' that:
// - Returns obj.size() if obj has size() method
// - Returns 1 if obj doesn't have size() method
//
// Example usage:
//   std::vector<int> v{1,2,3};
//   auto s1 = getSize(v);    // returns 3
//   auto s2 = getSize(42);   // returns 1
//
// YOUR CODE HERE:
// Trait to detect size():




// Function using the trait:




// ============================================================================
// EXERCISE 5.4: enable_if with Value Category
// ============================================================================
// TODO: Implement 'printValueCategory' that prints different messages
// Requirements:
// - First overload: for lvalue references, print "lvalue"
// - Second overload: for rvalue references, print "rvalue"
// - Use std::enable_if with std::is_lvalue_reference / std::is_rvalue_reference
// - Use perfect forwarding (T&&)
//
// Example usage:
//   int x = 5;
//   printValueCategory(x);      // "lvalue"
//   printValueCategory(10);     // "rvalue"
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 5.5: Container Trait Detection
// ============================================================================
// TODO: Implement 'printContainer' that works with any container
// Requirements:
// - Enabled only for types that have begin() and end() methods
// - Use SFINAE to detect iterator support
// - Print all elements separated by commas
//
// Example usage:
//   std::vector<int> v{1, 2, 3};
//   printContainer(v);  // prints "1, 2, 3"
//
// Hint: Use std::void_t or decltype with begin()/end()
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 5.6: Compile-Time Type Selection
// ============================================================================
// TODO: Implement 'safeDivide' with different behavior based on type
// Requirements:
// - For integral types: return std::optional<T> (empty if division by zero)
// - For floating point: return T (inf or nan is OK)
// - Use if constexpr (C++17) with std::is_integral
//
// Example usage:
//   auto a = safeDivide(10, 2);      // optional<int>(5)
//   auto b = safeDivide(10, 0);      // optional<int>() - empty
//   auto c = safeDivide(10.0, 0.0);  // inf
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 5.7: SFINAE with Multiple Conditions
// ============================================================================
// TODO: Implement 'smartCompare' with three overloads
// Requirements:
// - For arithmetic types: use <
// - For types with compare() method: use obj1.compare(obj2)
// - For pointer types: compare pointed-to values
// - Use std::enable_if with combined conditions
//
// Example usage:
//   smartCompare(5, 10);           // uses <
//   smartCompare(ptr1, ptr2);      // dereferences and compares
//
// YOUR CODE HERE:
// Arithmetic version:



// Pointer version:



// Types with compare method (advanced - can skip):



// ============================================================================
// EXERCISE 5.8: Iterator Category Detection
// ============================================================================
// TODO: Implement 'advance' that advances an iterator differently based on category
// Requirements:
// - For random access iterators: use it += n (O(1))
// - For other iterators: use loop with ++ (O(n))
// - Use std::iterator_traits and std::is_same
// - Detect std::random_access_iterator_tag
//
// Example usage:
//   std::vector<int>::iterator it = vec.begin();
//   advance(it, 5);  // uses += (fast)
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 5.9: Return Type SFINAE - auto with trailing return type
// ============================================================================
// TODO: Implement 'getFirst' that returns first element
// Requirements:
// - For containers with operator[]: return cont[0]
// - For containers without []: return *cont.begin()
// - Use auto with trailing return type and decltype
// - Use SFINAE to select appropriate version
//
// Example usage:
//   std::vector<int> v{1, 2, 3};
//   auto first = getFirst(v);  // returns 1
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 5.10: Void_t Trait Detection Pattern
// ============================================================================
// TODO: Implement has_push_back trait using std::void_t
// Requirements:
// - Create has_push_back<T, U> that detects if T has push_back(U) method
// - Use std::void_t and decltype
// - Implement using primary template + partial specialization
//
// Then implement addElement that:
// - Uses push_back if available
// - Otherwise inserts at end using insert
//
// Example usage:
//   std::vector<int> v;
//   addElement(v, 42);  // uses push_back
//
// YOUR CODE HERE:




} // namespace Ex05
