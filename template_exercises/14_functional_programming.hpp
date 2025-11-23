#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
#include <optional>
#include <variant>
#include <string>
#include <memory>

/**
 * Exercise 14: Functional Programming in C++
 *
 * Learning objectives:
 * - Apply functional programming paradigms in C++
 * - Implement map, filter, reduce patterns
 * - Master lambda expressions and closures
 * - Build composable function pipelines
 * - Understand monads: Optional, Result, State
 * - Implement currying and partial application
 */

namespace Ex14 {

// ============================================================================
// EXERCISE 14.1: Map - Transform Elements
// ============================================================================
// TODO: Implement a functional map that transforms each element
// Requirements:
// - Take a container and a transformation function
// - Return new container with transformed elements
// - Use templates to work with any container and function
// - Preserve container type
//
// Example usage:
//   std::vector<int> v = {1, 2, 3, 4};
//   auto squared = map(v, [](int x) { return x * x; });  // {1, 4, 9, 16}
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.2: Filter - Select Elements
// ============================================================================
// TODO: Implement a functional filter that selects elements
// Requirements:
// - Take a container and a predicate function
// - Return new container with only elements matching predicate
// - Work with any container type
//
// Example usage:
//   std::vector<int> v = {1, 2, 3, 4, 5, 6};
//   auto evens = filter(v, [](int x) { return x % 2 == 0; });  // {2, 4, 6}
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.3: Reduce/Fold - Aggregate Values
// ============================================================================
// TODO: Implement reduce (fold) to aggregate values
// Requirements:
// - Take container, initial value, and binary function
// - Accumulate all elements using the function
// - Return final accumulated value
//
// Example usage:
//   std::vector<int> v = {1, 2, 3, 4};
//   int sum = reduce(v, 0, [](int acc, int x) { return acc + x; });  // 10
//   int product = reduce(v, 1, std::multiplies<>());  // 24
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.4: Function Composition
// ============================================================================
// TODO: Implement function composition operator
// Requirements:
// - compose(f, g) creates function that does f(g(x))
// - Support chaining multiple functions
// - Use std::function or templates
// - Return type deduction
//
// Example usage:
//   auto addOne = [](int x) { return x + 1; };
//   auto double = [](int x) { return x * 2; };
//   auto f = compose(addOne, double);
//   int result = f(5);  // (5 * 2) + 1 = 11
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.5: Currying - Partial Application
// ============================================================================
// TODO: Implement currying to partially apply function arguments
// Requirements:
// - curry converts f(a, b, c) into f(a)(b)(c)
// - Support any number of arguments
// - Use variadic templates
// - Return callable for each partial application
//
// Example usage:
//   auto add = [](int a, int b, int c) { return a + b + c; };
//   auto curriedAdd = curry(add);
//   auto add5 = curriedAdd(5);
//   auto add5and3 = add5(3);
//   int result = add5and3(2);  // 5 + 3 + 2 = 10
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.6: Partial Application with std::bind Alternative
// ============================================================================
// TODO: Create a modern alternative to std::bind
// Requirements:
// - partial(f, args...) binds some arguments
// - Remaining arguments provided later
// - Use lambda captures instead of std::bind
// - Cleaner syntax than std::bind
//
// Example usage:
//   auto add = [](int a, int b, int c) { return a + b + c; };
//   auto add5and3 = partial(add, 5, 3);
//   int result = add5and3(2);  // 10
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.7: Maybe/Optional Monad
// ============================================================================
// TODO: Implement monadic operations for std::optional
// Requirements:
// - map: transform value if present
// - flatMap (bind): chain optional-returning functions
// - orElse: provide default value
// - Support method chaining
//
// Example usage:
//   std::optional<int> x = 42;
//   auto result = x.map([](int n) { return n * 2; })
//                  .flatMap([](int n) { return n > 50 ? std::optional{n} : std::nullopt; })
//                  .orElse(0);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.8: Result<T, E> Type (Railway-Oriented Programming)
// ============================================================================
// TODO: Implement Result type for error handling without exceptions
// Requirements:
// - Result<T, E> holds either success value T or error E
// - Use std::variant internally
// - Provide isOk(), isErr(), value(), error()
// - Implement map and flatMap for chaining
//
// Example usage:
//   Result<int, std::string> divide(int a, int b) {
//       if (b == 0) return Err("Division by zero");
//       return Ok(a / b);
//   }
//   auto result = divide(10, 2)
//       .map([](int x) { return x * 3; })  // 15
//       .orElse(0);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.9: Functor - Mappable Container
// ============================================================================
// TODO: Create a Functor concept and implement for containers
// Requirements:
// - Functor has fmap that preserves structure
// - Implement for std::vector, std::optional
// - Use templates to be generic
//
// Example usage:
//   std::vector<int> v = {1, 2, 3};
//   auto doubled = fmap(v, [](int x) { return x * 2; });
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.10: Lazy Evaluation Container
// ============================================================================
// TODO: Implement a container that delays computation until needed
// Requirements:
// - Lazy<T> stores a function to compute value
// - Value computed only once on first access
// - Subsequent accesses return cached value
// - Thread-safe optional
//
// Example usage:
//   Lazy<int> expensive([](){
//       std::cout << "Computing...\n";
//       return 42;
//   });
//   int x = expensive.value();  // Prints "Computing..."
//   int y = expensive.value();  // No print, uses cached value
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.11: Memoization
// ============================================================================
// TODO: Implement automatic memoization for pure functions
// Requirements:
// - memoize(f) returns new function that caches results
// - Use std::map to store argument -> result mapping
// - Support any number of arguments
// - Hash function for argument tuple
//
// Example usage:
//   auto fib = memoize([](auto& self, int n) -> int {
//       if (n <= 1) return n;
//       return self(self, n-1) + self(self, n-2);
//   });
//   int result = fib(fib, 40);  // Much faster with memoization
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.12: Pipeline Operator
// ============================================================================
// TODO: Implement pipeline operator for function chaining
// Requirements:
// - operator| to chain function calls
// - x | f | g | h is equivalent to h(g(f(x)))
// - Works with lambdas and function objects
// - Clean, readable syntax
//
// Example usage:
//   auto addOne = [](int x) { return x + 1; };
//   auto double = [](int x) { return x * 2; };
//   int result = 5 | addOne | double;  // (5 + 1) * 2 = 12
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.13: Higher-Order Functions - forEach, any, all
// ============================================================================
// TODO: Implement common higher-order functions
// Requirements:
// - forEach: apply function to each element (side effects)
// - any: true if predicate true for any element
// - all: true if predicate true for all elements
//
// Example usage:
//   std::vector<int> v = {1, 2, 3, 4};
//   forEach(v, [](int x) { std::cout << x << " "; });
//   bool hasEven = any(v, [](int x) { return x % 2 == 0; });  // true
//   bool allPositive = all(v, [](int x) { return x > 0; });  // true
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.14: Applicative Functor
// ============================================================================
// TODO: Implement applicative pattern for applying wrapped functions
// Requirements:
// - Apply function wrapped in context to value in context
// - std::optional<F> applied to std::optional<T>
// - Useful for validations and combinations
//
// Example usage:
//   std::optional<int> x = 5;
//   std::optional<int> y = 3;
//   auto add = [](int a) { return [a](int b) { return a + b; }; };
//   auto result = apply(fmap(x, add), y);  // std::optional{8}
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.15: Monadic List Operations
// ============================================================================
// TODO: Implement flatMap/bind for containers
// Requirements:
// - flatMap applies function returning container and flattens
// - Useful for one-to-many transformations
// - Implement flatten to collapse nested containers
//
// Example usage:
//   std::vector<int> v = {1, 2, 3};
//   auto duplicate = [](int x) { return std::vector{x, x}; };
//   auto result = flatMap(v, duplicate);  // {1, 1, 2, 2, 3, 3}
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.16: Y Combinator for Recursion
// ============================================================================
// TODO: Implement Y combinator for anonymous recursion
// Requirements:
// - Allow lambda to call itself recursively
// - Y combinator takes non-recursive function and makes it recursive
// - Demonstrate with factorial or fibonacci
//
// Example usage:
//   auto fib = Y([](auto self, int n) -> int {
//       if (n <= 1) return n;
//       return self(n-1) + self(n-2);
//   });
//   int result = fib(10);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.17: Transducers - Composable Transformations
// ============================================================================
// TODO: Implement transducers for efficient composition
// Requirements:
// - Combine map, filter operations without intermediate allocations
// - Single pass over data
// - Compose transformations before applying
//
// Example usage:
//   auto xform = compose(
//       mapping([](int x) { return x * 2; }),
//       filtering([](int x) { return x > 5; })
//   );
//   std::vector<int> result = transduce(xform, {1, 2, 3, 4, 5});
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 14.18: Zipper for Tree Navigation
// ============================================================================
// TODO: Implement zipper data structure for functional tree traversal
// Requirements:
// - Navigate tree while maintaining path
// - Support up, down, left, right movements
// - Immutable updates
// - Reconstruct tree after modifications
//
// Example usage:
//   TreeZipper z = makeZipper(tree);
//   z = z.down().right().modify([](int x) { return x * 2; });
//   Tree newTree = z.toTree();
//
// YOUR CODE HERE:




} // namespace Ex14
