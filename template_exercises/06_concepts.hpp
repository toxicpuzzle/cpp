#pragma once
#include <concepts>
#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

/**
 * Exercise 06: C++20 Concepts
 *
 * Learning objectives:
 * - Understand concept syntax
 * - Create custom concepts
 * - Use standard library concepts
 * - Apply constraints to templates
 *
 * Note: Requires C++20 compiler support
 */

namespace Ex06 {

// ============================================================================
// EXERCISE 6.1: Basic Concept Definition
// ============================================================================
// TODO: Define a concept 'Numeric' for arithmetic types
// Requirements:
// - Use std::is_arithmetic_v
// - Then implement 'square' function constrained by Numeric
//
// Example usage:
//   auto x = square(5);      // OK
//   auto y = square(3.14);   // OK
//   // auto z = square("hi"); // Compile error
//
// YOUR CODE HERE:
// Concept definition:



// Function using the concept:




// ============================================================================
// EXERCISE 6.2: Concept with Multiple Requirements
// ============================================================================
// TODO: Define a concept 'Comparable' that requires operator<
// Requirements:
// - Use requires expression
// - Check that T has operator< with another T
// - Check that result is convertible to bool
//
// Then implement 'getMin' function using this concept
//
// Example usage:
//   auto m = getMin(5, 10);  // returns 5
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 6.3: Concept Composition
// ============================================================================
// TODO: Define concepts and combine them
// Requirements:
// - Define 'Incrementable': requires ++t
// - Define 'Decrementable': requires --t
// - Define 'Bidirectional': combines both (use &&)
// - Implement 'moveForwardAndBack' using Bidirectional
//
// Example usage:
//   int x = 5;
//   moveForwardAndBack(x);  // x becomes 5 again (++, then --)
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 6.4: Container Concept
// ============================================================================
// TODO: Define a concept 'Container' for types with begin(), end(), size()
// Requirements:
// - Check for begin() and end() methods
// - Check for size() method
// - Implement 'printSize' function using this concept
//
// Example usage:
//   std::vector<int> v{1, 2, 3};
//   printSize(v);  // prints 3
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 6.5: Concept for Callable
// ============================================================================
// TODO: Define a concept 'Predicate' for callables returning bool
// Requirements:
// - Takes a callable F and argument type T
// - Requires F can be called with T
// - Result must be convertible to bool
// - Implement 'countIf' using this concept
//
// Example usage:
//   std::vector<int> v{1, 2, 3, 4, 5};
//   auto n = countIf(v, [](int x) { return x > 3; });  // returns 2
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 6.6: Concept Overloading
// ============================================================================
// TODO: Create overloaded 'process' functions using different concepts
// Requirements:
// - First version: constrained by std::integral, returns value * 2
// - Second version: constrained by std::floating_point, returns value / 2
// - Third version: constrained by std::is_pointer, dereferences and processes
//
// Example usage:
//   auto a = process(10);     // integral: 20
//   auto b = process(10.0);   // floating: 5.0
//   int x = 10;
//   auto c = process(&x);     // pointer: 20
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 6.7: Concept with Nested Requirements
// ============================================================================
// TODO: Define 'Range' concept with nested type requirements
// Requirements:
// - Requires begin() and end()
// - Requires value_type nested type
// - Implement 'sumRange' that sums all elements
//
// Example usage:
//   std::vector<int> v{1, 2, 3};
//   auto s = sumRange(v);  // returns 6
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 6.8: Custom Iterator Concept
// ============================================================================
// TODO: Define 'ForwardIterator' concept
// Requirements:
// - Requires operator++
// - Requires operator*
// - Requires operator!=
// - Implement 'distance' function using this concept
//
// Example usage:
//   std::vector<int> v{1, 2, 3, 4, 5};
//   auto d = distance(v.begin(), v.end());  // returns 5
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 6.9: Concept for Printable Types
// ============================================================================
// TODO: Define 'Printable' concept (like you saw in neural_network/own_templates.h)
// Requirements:
// - Requires that type T can be used with std::ostream <<
// - Implement 'printAll' for vector of Printable elements
//
// Example usage:
//   std::vector<int> v{1, 2, 3};
//   printAll(v);  // prints "1 2 3 "
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 6.10: Concept for Class with Specific Members
// ============================================================================
// TODO: Define 'Matrix' concept for matrix-like types
// Requirements:
// - Requires rows() method returning integral
// - Requires cols() method returning integral
// - Requires operator()(size_t, size_t) for element access
// - Implement 'printDimensions' using this concept
//
// Example usage:
//   MyMatrix m;  // assuming it satisfies concept
//   printDimensions(m);  // prints "Rows: X, Cols: Y"
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 6.11: Subsumption and Concept Refinement
// ============================================================================
// TODO: Demonstrate concept subsumption
// Requirements:
// - Define 'Addable': requires operator+
// - Define 'Multipliable': requires operator*
// - Define 'Arithmetic': requires both (use Addable && Multipliable)
// - Implement three overloads of 'compute' showing subsumption
//
// Example usage:
//   compute(5);  // calls most specific version
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 6.12: Concept with requires clause
// ============================================================================
// TODO: Define a concept using a requires clause with compound requirements
// Requirements:
// - Define 'Swappable': requires std::swap can be called on two T objects
// - Check both that swap exists and is noexcept
// - Implement 'swapIfGreater' using this concept
//
// Example usage:
//   int a = 10, b = 5;
//   swapIfGreater(a, b);  // a=5, b=10 now
//
// YOUR CODE HERE:




} // namespace Ex06
