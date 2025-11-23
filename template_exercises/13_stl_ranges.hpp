#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <ranges>
#include <span>
#include <string>
#include <functional>

/**
 * Exercise 13: Advanced STL & Ranges (C++20)
 *
 * Learning objectives:
 * - Master STL algorithms and their modern equivalents
 * - Understand C++20 ranges and views for lazy evaluation
 * - Build custom iterators for complex data structures
 * - Use std::span for non-owning array views
 * - Apply composable range operations
 */

namespace Ex13 {

// ============================================================================
// EXERCISE 13.1: Transform and Accumulate
// ============================================================================
// TODO: Implement a function that squares all elements and returns their sum
// Requirements:
// - Use std::transform to square each element
// - Use std::accumulate to sum the results
// - Return the final sum
// - Handle empty vectors (return 0)
//
// Example usage:
//   std::vector<int> v = {1, 2, 3, 4};
//   int result = sumOfSquares(v);  // 1 + 4 + 9 + 16 = 30
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.2: Custom Iterator - Range Iterator
// ============================================================================
// TODO: Implement a range iterator that generates numbers [start, end)
// Requirements:
// - Create RangeIterator class with iterator traits
// - Support iterator_category, value_type, difference_type, pointer, reference
// - Implement operators: ++, *, ==, !=
// - Create Range class with begin() and end()
//
// Example usage:
//   for (int i : Range(1, 10)) {
//       std::cout << i << " ";  // prints 1 2 3 4 5 6 7 8 9
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.3: Fibonacci Iterator
// ============================================================================
// TODO: Create an iterator that generates Fibonacci numbers
// Requirements:
// - FibonacciIterator generates next Fibonacci number on ++
// - Support dereference to get current value
// - Create FibonacciSequence class with begin() and sentinel end
// - Make it work with range-based for loop
//
// Example usage:
//   FibonacciSequence fib;
//   auto it = fib.begin();
//   for (int i = 0; i < 10; ++i, ++it) {
//       std::cout << *it << " ";  // 0 1 1 2 3 5 8 13 21 34
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.4: Filter Iterator
// ============================================================================
// TODO: Implement a filtering iterator that skips elements not matching predicate
// Requirements:
// - FilterIterator wraps another iterator
// - Skips elements where predicate returns false
// - Advances to next valid element automatically
// - Support all required iterator operations
//
// Example usage:
//   std::vector<int> v = {1, 2, 3, 4, 5, 6};
//   auto isEven = [](int x) { return x % 2 == 0; };
//   // FilterRange that yields only 2, 4, 6
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.5: C++20 Ranges - Transform View
// ============================================================================
// TODO: Use ranges to transform and filter data lazily
// Requirements:
// - Take a vector of integers
// - Filter for even numbers
// - Square each number
// - Return first 5 results as vector
// - Use std::ranges::views for lazy evaluation
//
// Example usage:
//   std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   auto result = transformAndFilter(v);  // {4, 16, 36, 64, 100}
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.6: Custom Range Adapter
// ============================================================================
// TODO: Create a custom range adapter for chunking
// Requirements:
// - ChunkView splits a range into fixed-size chunks
// - Each chunk is a subrange
// - Works with C++20 ranges
// - Support iteration over chunks
//
// Example usage:
//   std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
//   for (auto chunk : ChunkView(v, 3)) {
//       // First iteration: {1, 2, 3}
//       // Second iteration: {4, 5, 6}
//       // Third iteration: {7, 8}
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.7: std::span Usage
// ============================================================================
// TODO: Implement a function using std::span to process array-like data
// Requirements:
// - processArray takes std::span<const int>
// - Works with vector, array, C-array, etc.
// - Returns sum of elements
// - Demonstrate subspan usage
//
// Example usage:
//   std::vector<int> v = {1, 2, 3, 4, 5};
//   int arr[] = {1, 2, 3};
//   int sum1 = processArray(v);  // Works!
//   int sum2 = processArray(arr);  // Also works!
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.8: Partition and Sort
// ============================================================================
// TODO: Partition data and sort each partition
// Requirements:
// - Partition vector into even/odd numbers
// - Sort each partition separately
// - Use std::partition or std::stable_partition
// - Return the partition point iterator
//
// Example usage:
//   std::vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4};
//   auto mid = partitionAndSort(v);
//   // v is now [2, 4, 8, 1, 3, 5, 7, 9] or similar
//   //           ^even^    ^odd^
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.9: Multi-Key Sorting with Custom Comparator
// ============================================================================
// TODO: Sort a collection with multiple keys
// Requirements:
// - Create Person struct with name and age
// - Sort by age first, then by name
// - Use custom comparator
// - Demonstrate std::sort usage
//
// Example usage:
//   std::vector<Person> people = {{"Alice", 30}, {"Bob", 25}, {"Alice", 25}};
//   sortPeople(people);
//   // Result: Bob-25, Alice-25, Alice-30
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.10: Zip Iterator
// ============================================================================
// TODO: Create a zip iterator that iterates over multiple ranges simultaneously
// Requirements:
// - ZipIterator holds iterators from two ranges
// - Dereference returns std::pair of references
// - Useful for iterating two containers together
// - Support increment and comparison
//
// Example usage:
//   std::vector<int> keys = {1, 2, 3};
//   std::vector<std::string> values = {"a", "b", "c"};
//   for (auto [k, v] : zip(keys, values)) {
//       std::cout << k << ": " << v << "\n";
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.11: Ranges Pipeline Composition
// ============================================================================
// TODO: Build a complex data pipeline using ranges
// Requirements:
// - Start with vector of strings
// - Filter strings longer than 3 characters
// - Transform to uppercase
// - Take first 5 elements
// - Collect into vector
// - Use views::filter, views::transform, views::take
//
// Example usage:
//   std::vector<std::string> words = {"hi", "hello", "world", "a", "test", "data"};
//   auto result = buildPipeline(words);  // {"HELLO", "WORLD", "TEST", "DATA"}
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.12: Custom Algorithm - Find Pattern
// ============================================================================
// TODO: Implement an algorithm to find a pattern in a sequence
// Requirements:
// - findPattern searches for a subsequence in a range
// - Returns iterator to first match
// - Uses std::search or implements manually
// - Works with any comparable type
//
// Example usage:
//   std::vector<int> data = {1, 2, 3, 4, 5, 3, 4, 6};
//   std::vector<int> pattern = {3, 4};
//   auto it = findPattern(data.begin(), data.end(), pattern.begin(), pattern.end());
//   // it points to first 3
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.13: Sliding Window View
// ============================================================================
// TODO: Create a sliding window view over a range
// Requirements:
// - SlidingWindowView yields overlapping windows
// - Window size is configurable
// - Returns spans or subranges
// - Useful for moving averages, pattern matching
//
// Example usage:
//   std::vector<int> v = {1, 2, 3, 4, 5};
//   for (auto window : SlidingWindowView(v, 3)) {
//       // {1,2,3}, {2,3,4}, {3,4,5}
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.14: Set Operations with Ranges
// ============================================================================
// TODO: Implement set operations using STL algorithms
// Requirements:
// - union: combine two sorted ranges
// - intersection: common elements
// - difference: elements in first but not second
// - Use std::set_union, std::set_intersection, std::set_difference
//
// Example usage:
//   std::vector<int> a = {1, 2, 3, 4};
//   std::vector<int> b = {3, 4, 5, 6};
//   auto u = setUnion(a, b);  // {1, 2, 3, 4, 5, 6}
//   auto i = setIntersection(a, b);  // {3, 4}
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 13.15: Lazy Evaluation with Generator
// ============================================================================
// TODO: Create a generator class that produces values lazily
// Requirements:
// - Generator stores a function that produces next value
// - Can be used in range-based for loop
// - Demonstrates lazy evaluation benefits
// - Infinite sequence support with take(n)
//
// Example usage:
//   auto gen = Generator([n=0]() mutable { return n++; });
//   for (int i : gen | views::take(5)) {
//       std::cout << i;  // 0 1 2 3 4
//   }
//
// YOUR CODE HERE:




} // namespace Ex13
