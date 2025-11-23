#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * Exercise 01: Function Templates Basics
 *
 * Learning objectives:
 * - Understand basic function template syntax
 * - Learn about template type deduction
 * - Use explicit template parameters
 * - Handle multiple template parameters
 */

namespace Ex01 {

// ============================================================================
// EXERCISE 1.1: Basic Function Template
// ============================================================================
// TODO: Implement a template function 'myMax' that returns the larger of two values
// Requirements:
// - Should work with any type that supports operator<
// - Return type should be the same as input type
// - Use ternary operator for comparison
//
// Example usage:
//   int a = myMax(5, 10);        // returns 10
//   double b = myMax(3.14, 2.71); // returns 3.14
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 1.2: Function Template with Multiple Parameters
// ============================================================================
// TODO: Implement a template function 'mySwap' that swaps two values
// Requirements:
// - Take two references as parameters
// - Swap their values using a temporary variable
// - Return void
//
// Example usage:
//   int x = 5, y = 10;
//   mySwap(x, y);  // x is now 10, y is now 5
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 1.3: Template with Explicit Type Specification
// ============================================================================
// TODO: Implement 'convertAndAdd' that converts two values to type T and adds them
// Requirements:
// - Takes two parameters of potentially different types (U and V)
// - Converts both to type T using static_cast
// - Returns their sum as type T
//
// Example usage:
//   auto result = convertAndAdd<double>(5, 3.14);  // returns 8.14
//   auto result2 = convertAndAdd<int>(5.5, 3.7);   // returns 8
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 1.4: Template with Default Type
// ============================================================================
// TODO: Implement 'makeDefault' that creates a default-initialized value
// Requirements:
// - Template parameter should default to int if not specified
// - Return a default-constructed value of type T
//
// Example usage:
//   auto x = makeDefault();        // returns 0 (int)
//   auto y = makeDefault<double>(); // returns 0.0
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 1.5: Template Function with Container
// ============================================================================
// TODO: Implement 'printContainer' that prints all elements in a container
// Requirements:
// - Take a const reference to a container
// - Print each element separated by spaces
// - Print a newline at the end
// - Should work with vector, array, list, etc.
//
// Example usage:
//   std::vector<int> vec{1, 2, 3};
//   printContainer(vec);  // prints "1 2 3\n"
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 1.6: Template with Non-Type Parameter
// ============================================================================
// TODO: Implement 'power' that raises a value to a compile-time power
// Requirements:
// - First template parameter is the type T
// - Second template parameter is an int N (the power)
// - Calculate x^N at runtime using a loop
// - Return T
//
// Example usage:
//   auto x = power<int, 3>(2);     // returns 8 (2^3)
//   auto y = power<double, 2>(3.0); // returns 9.0 (3^2)
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 1.7: Template with Return Type Deduction
// ============================================================================
// TODO: Implement 'multiply' that multiplies two values of potentially different types
// Requirements:
// - Use 'auto' return type
// - Let the compiler deduce the return type from the multiplication
// - Parameters can be different types
//
// Example usage:
//   auto x = multiply(3, 4.5);      // returns 13.5 (double)
//   auto y = multiply(2.0f, 3.0f);  // returns 6.0f (float)
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 1.8: Overloaded Template
// ============================================================================
// TODO: Implement two overloaded 'process' functions
// Requirements:
// - First version: Takes a single value of type T, returns it unchanged
// - Second version: Takes two values of type T, returns their sum
// - Both should be templates
//
// Example usage:
//   auto x = process(5);        // returns 5
//   auto y = process(5, 10);    // returns 15
//
// YOUR CODE HERE:





} // namespace Ex01
