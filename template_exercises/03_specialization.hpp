#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <type_traits>

/**
 * Exercise 03: Template Specialization
 *
 * Learning objectives:
 * - Understand full template specialization
 * - Learn partial template specialization
 * - Use specialization for type-specific optimizations
 * - Handle special cases for specific types
 */

namespace Ex03 {

// ============================================================================
// EXERCISE 3.1: Full Function Template Specialization
// ============================================================================
// TODO: Implement a generic 'compare' template and specialize it for const char*
// Requirements:
// - Generic version: compare two values using operator==
// - Specialized version for const char*: use strcmp
// - Both return bool
//
// Example usage:
//   compare(5, 5);           // uses generic version, returns true
//   compare("hi", "hi");     // uses specialized version, returns true
//
// YOUR CODE HERE:
// Generic template:



// Specialization for const char*:




// ============================================================================
// EXERCISE 3.2: Class Template Specialization
// ============================================================================
// TODO: Implement a 'Storage' class template with specialization for bool
// Requirements:
// - Generic version: stores value of type T in member T m_value
// - Specialized version for bool: stores value as a single bit in unsigned char
// - Both have: constructor, getValue(), setValue()
// - The bool version should use bitwise operations
//
// Example usage:
//   Storage<int> si{42};
//   Storage<bool> sb{true};
//
// YOUR CODE HERE:
// Generic template:




// Specialization for bool:




// ============================================================================
// EXERCISE 3.3: Partial Specialization - Pointer Types
// ============================================================================
// TODO: Implement a 'TypeInfo' class template with partial specialization for pointers
// Requirements:
// - Generic version: static method name() returns "Generic type"
// - Pointer specialization: static method name() returns "Pointer type"
// - Reference specialization: static method name() returns "Reference type"
//
// Example usage:
//   TypeInfo<int>::name();    // "Generic type"
//   TypeInfo<int*>::name();   // "Pointer type"
//   TypeInfo<int&>::name();   // "Reference type"
//
// YOUR CODE HERE:
// Generic template:



// Partial specialization for pointers:



// Partial specialization for references:




// ============================================================================
// EXERCISE 3.4: Partial Specialization - Template Template Parameters
// ============================================================================
// TODO: Implement 'ContainerWrapper' with partial specialization
// Requirements:
// - Generic version: works with any type T, has message() returning "Not a container"
// - Partial specialization for template<typename> class C: recognizes std::vector, etc.
// - Specialized version message() returns "Container type"
//
// Example usage:
//   ContainerWrapper<int>::message();              // "Not a container"
//   ContainerWrapper<std::vector<int>>::message(); // "Container type"
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 3.5: Specialization for Optimization
// ============================================================================
// TODO: Implement 'copy' function with optimization for POD types
// Requirements:
// - Generic version: use a loop to copy N elements from src to dst
// - Specialized version for arithmetic types: use memcpy for efficiency
// - Use std::is_arithmetic to detect arithmetic types (provide two overloads using SFINAE)
//
// Example usage:
//   int src[] = {1, 2, 3};
//   int dst[3];
//   copy(src, dst, 3);  // uses memcpy version
//
// Hint: Use std::enable_if as a template parameter
//
// YOUR CODE HERE:
// Generic version (non-arithmetic types):




// Optimized version (arithmetic types):




// ============================================================================
// EXERCISE 3.6: Specialization with Different Interface
// ============================================================================
// TODO: Implement a 'Printer' class with different interfaces for different types
// Requirements:
// - Generic version: print(T value) outputs value using <<
// - Specialized for std::vector<T>: print() outputs all elements in brackets
// - Specialized for std::pair<T,U>: print() outputs (first, second)
//
// Example usage:
//   Printer<int> p1;
//   p1.print(42);                          // "42"
//   Printer<std::vector<int>> p2;
//   p2.print({1,2,3});                     // "[1, 2, 3]"
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 3.7: Specialization for std::string
// ============================================================================
// TODO: Implement 'getDefaultValue' with specializations
// Requirements:
// - Generic version: return T{} (default constructor)
// - Specialized for int: return 0
// - Specialized for double: return 0.0
// - Specialized for std::string: return "default"
// - Specialized for pointer types: return nullptr
//
// Example usage:
//   auto x = getDefaultValue<int>();        // 0
//   auto s = getDefaultValue<std::string>(); // "default"
//   auto p = getDefaultValue<int*>();       // nullptr
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 3.8: Partial Specialization for Multiple Parameters
// ============================================================================
// TODO: Implement 'PairProcessor' class with various specializations
// Requirements:
// - Generic version PairProcessor<T, U>: method process() returns "Different types"
// - Partial specialization PairProcessor<T, T>: process() returns "Same types"
// - Full specialization PairProcessor<int, int>: process() returns "Both integers"
//
// Example usage:
//   PairProcessor<int, double>::process();  // "Different types"
//   PairProcessor<double, double>::process(); // "Same types"
//   PairProcessor<int, int>::process();     // "Both integers"
//
// YOUR CODE HERE:




} // namespace Ex03
