#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>

/**
 * Exercise 04: Variadic Templates
 *
 * Learning objectives:
 * - Understand parameter packs
 * - Use pack expansion
 * - Implement recursive template functions
 * - Master fold expressions (C++17)
 */

namespace Ex04 {

// ============================================================================
// EXERCISE 4.1: Basic Variadic Function - Recursive
// ============================================================================
// TODO: Implement 'print' that prints all arguments separated by spaces
// Requirements:
// - Use recursion with base case and recursive case
// - Base case: empty function for no arguments
// - Recursive case: print first argument, then recurse on rest
//
// Example usage:
//   print(1, 2.5, "hello", 'c');  // prints "1 2.5 hello c\n"
//
// YOUR CODE HERE:
// Base case:


// Recursive case:




// ============================================================================
// EXERCISE 4.2: Variadic Function with Fold Expression
// ============================================================================
// TODO: Implement 'sum' that adds all arguments using fold expression
// Requirements:
// - Use C++17 fold expression (... + args)
// - Return the sum of all arguments
// - Should work with any numeric types
//
// Example usage:
//   auto x = sum(1, 2, 3, 4, 5);  // returns 15
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 4.3: Count Arguments
// ============================================================================
// TODO: Implement 'countArgs' that returns the number of arguments
// Requirements:
// - Use sizeof... operator
// - Return size_t
//
// Example usage:
//   auto n = countArgs(1, "hi", 3.14);  // returns 3
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 4.4: Variadic Template - All Same Type
// ============================================================================
// TODO: Implement 'average' that computes the average of all arguments
// Requirements:
// - All arguments must be the same type T
// - Use fold expression to sum
// - Return double
// - Handle empty case by returning 0.0
//
// Example usage:
//   auto avg = average(1.0, 2.0, 3.0, 4.0);  // returns 2.5
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 4.5: Variadic Template Class
// ============================================================================
// TODO: Implement 'Tuple' class that stores heterogeneous values
// Requirements:
// - Use std::tuple internally (member variable m_data)
// - Constructor: takes variadic arguments and forwards to tuple
// - get<N>(): return the Nth element (use std::get)
// - size(): return number of elements (use std::tuple_size)
//
// Example usage:
//   Tuple<int, double, std::string> t{42, 3.14, "hello"};
//   auto x = t.get<0>();  // returns 42
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 4.6: Recursive Variadic - Find Maximum
// ============================================================================
// TODO: Implement 'maximum' that finds the maximum value among arguments
// Requirements:
// - Use recursion
// - Base case: single argument returns that argument
// - Recursive case: compare first with maximum of rest
// - Use std::common_type for return type
//
// Example usage:
//   auto m = maximum(3, 7, 2, 9, 4);  // returns 9
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 4.7: Variadic with Different Types - makeVector
// ============================================================================
// TODO: Implement 'makeVector' that creates a vector from variadic arguments
// Requirements:
// - All arguments must be convertible to type T
// - Return std::vector<T>
// - Use initializer list or push_back in fold expression
//
// Example usage:
//   auto vec = makeVector<double>(1, 2.5, 3);  // vector<double>{1.0, 2.5, 3.0}
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 4.8: Variadic Perfect Forwarding
// ============================================================================
// TODO: Implement 'makeUnique' that creates a unique_ptr with constructor args
// Requirements:
// - Template parameters: type T and variadic Args
// - Use perfect forwarding (std::forward)
// - Return std::unique_ptr<T>
// - Forward all arguments to T's constructor
//
// Example usage:
//   auto ptr = makeUnique<std::string>(5, 'a');  // unique_ptr to "aaaaa"
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 4.9: Logical Operations with Fold
// ============================================================================
// TODO: Implement 'allTrue' and 'anyTrue' using fold expressions
// Requirements:
// - allTrue: return true if all arguments are true (use && fold)
// - anyTrue: return true if any argument is true (use || fold)
// - Both take variadic bool arguments
//
// Example usage:
//   bool a = allTrue(true, true, true);     // true
//   bool b = allTrue(true, false, true);    // false
//   bool c = anyTrue(false, false, true);   // true
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 4.10: Variadic Index Sequence
// ============================================================================
// TODO: Implement 'applyToTuple' that applies a function to all tuple elements
// Requirements:
// - Take a tuple and a function
// - Apply function to each element in the tuple
// - Use std::index_sequence and helper function
// - Print results separated by spaces
//
// Example usage:
//   auto t = std::make_tuple(1, 2.5, 3);
//   applyToTuple(t, [](auto x) { std::cout << x * 2 << " "; });
//   // prints "2 5 6"
//
// Hint: This is advanced - you'll need a helper with index_sequence
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 4.11: Concatenate Strings
// ============================================================================
// TODO: Implement 'concat' that concatenates all string arguments
// Requirements:
// - Take variadic arguments of any type convertible to string
// - Use fold expression with string concatenation
// - Return std::string
//
// Example usage:
//   auto s = concat("Hello", " ", "World", "!", " ", 42);
//   // returns "Hello World! 42"
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 4.12: Visit Each Argument
// ============================================================================
// TODO: Implement 'forEach' that applies a function to each argument
// Requirements:
// - Take a function/lambda and variadic arguments
// - Apply the function to each argument in order
// - Use fold expression with comma operator
//
// Example usage:
//   forEach([](auto x) { std::cout << x << "\n"; }, 1, 2.5, "hi");
//   // prints each on a new line
//
// YOUR CODE HERE:




} // namespace Ex04
