#pragma once
#include <iostream>
#include <memory>
#include <type_traits>
#include <functional>
#include <any>
#include <variant>
#include <optional>

/**
 * Exercise 12: Advanced Type Techniques
 *
 * Learning objectives:
 * - Implement type erasure from scratch
 * - Create strong type wrappers
 * - Use std::variant for type-safe unions
 * - Apply std::optional for optional values
 * - Implement phantom types
 * - Create compile-time type lists
 * - Use tag types for dispatch and SFINAE
 */

namespace Ex12 {

// ============================================================================
// EXERCISE 12.1: Type Erasure - Basic Implementation
// ============================================================================
// TODO: Implement basic type erasure similar to std::any
// Requirements:
// - Create SimpleAny class that can store any type
// - Use concept: stored type must be copyable
// - Implement: constructor, copy, get<T>(), has_value()
// - Throw bad_cast if wrong type requested
//
// Example usage:
//   SimpleAny a = 42;
//   int x = a.get<int>();  // OK
//   // std::string s = a.get<std::string>();  // throws
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.2: Type Erasure - Function Wrapper
// ============================================================================
// TODO: Implement a simplified std::function using type erasure
// Requirements:
// - Create Function<R(Args...)> template
// - Store any callable (function, lambda, functor)
// - Implement operator() to invoke stored callable
// - Handle empty state
//
// Example usage:
//   Function<int(int, int)> f = [](int a, int b) { return a + b; };
//   int result = f(3, 4);  // 7
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.3: Strong Types (Named Types)
// ============================================================================
// TODO: Create a strong type system to prevent type confusion
// Requirements:
// - Create StrongType<T, Tag> template
// - Prevent implicit conversion between different strong types
// - Provide explicit get() for underlying value
// - Implement operators: ==, !=, <, <<
// - Create type aliases: Meters, Seconds, UserId, etc.
//
// Example usage:
//   Meters distance{100};
//   Seconds time{10};
//   // auto speed = distance / time;  // compilation error
//   double d = distance.get();  // explicit access
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.4: Phantom Types for Type State
// ============================================================================
// TODO: Use phantom types to enforce state at compile time
// Requirements:
// - Create File<State> template where State is a tag type
// - Define states: Closed, Open, Locked
// - Only certain operations allowed in certain states
// - Transitions return new type: File<Closed> -> File<Open>
//
// Example usage:
//   File<Closed> f("data.txt");
//   File<Open> fo = f.open();
//   fo.write("data");
//   // f.write("data");  // compilation error: file is Closed
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.5: std::variant for Type-Safe Union
// ============================================================================
// TODO: Use std::variant to create type-safe discriminated union
// Requirements:
// - Create Result<T, E> type using std::variant<T, E>
// - Add methods: isOk(), isErr(), unwrap(), unwrapOr()
// - Use std::visit for pattern matching
// - Create helper function ok<T>(val) and err<E>(val)
//
// Example usage:
//   Result<int, std::string> r = ok(42);
//   if (r.isOk()) {
//       int val = r.unwrap();
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.6: Visitor for std::variant
// ============================================================================
// TODO: Create visitor patterns for std::variant
// Requirements:
// - Create Shape variant: Circle, Rectangle, Triangle
// - Implement visitors using std::visit
// - Create area visitor
// - Create perimeter visitor
// - Create draw visitor
//
// Example usage:
//   Shape shape = Circle{5.0};
//   double a = std::visit(AreaVisitor{}, shape);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.7: std::optional for Optional Values
// ============================================================================
// TODO: Use std::optional properly with monadic operations
// Requirements:
// - Create SafeCalculator with methods returning optional<double>
// - Methods: divide, sqrt, log (return nullopt for invalid inputs)
// - Chain operations using and_then, transform, or_else
// - Implement map combinator
//
// Example usage:
//   auto result = divide(10, 2)
//       .and_then([](double x) { return sqrt(x); })
//       .transform([](double x) { return x * 2; })
//       .value_or(0.0);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.8: Type List Metaprogramming
// ============================================================================
// TODO: Implement compile-time type list operations
// Requirements:
// - Create TypeList<Ts...> template
// - Implement: Length, Front, Back, PushFront, PushBack
// - Implement: At<N>, Contains<T>, IndexOf<T>
// - Implement: Transform<Metafunction>, Filter<Predicate>
//
// Example usage:
//   using List = TypeList<int, double, char>;
//   using First = Front<List>;  // int
//   constexpr size_t len = Length<List>::value;  // 3
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.9: Tag Dispatching for Algorithm Selection
// ============================================================================
// TODO: Implement tag dispatching for different algorithms
// Requirements:
// - Create tag types: FastTag, SafeTag, BalancedTag
// - Create sort function overloads for each tag
// - Implement dispatch based on tag parameter
// - Add compile-time selection using traits
//
// Example usage:
//   std::vector<int> vec{3, 1, 4, 1, 5};
//   sort(vec, FastTag{});      // uses quick sort
//   sort(vec, SafeTag{});      // uses merge sort
//   sort(vec, BalancedTag{});  // uses heap sort
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.10: Empty Base Optimization (EBO)
// ============================================================================
// TODO: Demonstrate and utilize Empty Base Optimization
// Requirements:
// - Create CompressedPair<T1, T2> that uses EBO
// - If either type is empty, no space overhead
// - Provide first() and second() accessors
// - Compare sizeof with std::pair
//
// Example usage:
//   CompressedPair<int, EmptyClass> cp;
//   // sizeof(cp) == sizeof(int), not sizeof(int) + sizeof(EmptyClass)
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.11: Policy-Based Class Design
// ============================================================================
// TODO: Create a container with configurable policies
// Requirements:
// - Create Vector<T, AllocPolicy, GrowthPolicy, ThreadPolicy>
// - AllocPolicy: StandardAlloc, PoolAlloc, StackAlloc
// - GrowthPolicy: DoubleGrowth, FixedGrowth
// - ThreadPolicy: SingleThreaded, MultiThreaded
// - Use policies to customize behavior
//
// Example usage:
//   Vector<int, PoolAlloc, DoubleGrowth, MultiThreaded> vec;
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.12: Traits Classes
// ============================================================================
// TODO: Implement custom traits classes for generic programming
// Requirements:
// - Create IteratorTraits<T> for different iterator types
// - Create NumericTraits<T> with: min, max, epsilon
// - Create ContainerTraits<T> with: value_type, size_type
// - Use traits in generic algorithms
//
// Example usage:
//   using ValueType = ContainerTraits<std::vector<int>>::value_type;
//   constexpr auto max_val = NumericTraits<int>::max();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.13: Dependent False for static_assert
// ============================================================================
// TODO: Create always_false helper for better static_assert in templates
// Requirements:
// - Implement always_false<T> that is always false
// - Use in static_assert inside templates
// - Show difference from static_assert(false)
// - Apply in if constexpr branches
//
// Example usage:
//   template<typename T>
//   void foo() {
//       if constexpr (std::is_integral_v<T>) {
//           // ...
//       } else {
//           static_assert(always_false<T>, "T must be integral");
//       }
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.14: Member Detector Using Concept
// ============================================================================
// TODO: Create concepts to detect member functions/types
// Requirements:
// - Create HasSize concept (detects .size())
// - Create HasBeginEnd concept (detects .begin() and .end())
// - Create HasValueType concept (detects ::value_type)
// - Use in constrained templates
//
// Example usage:
//   template<HasSize T>
//   size_t getSize(const T& container) {
//       return container.size();
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.15: Opaque Typedef Pattern
// ============================================================================
// TODO: Create truly opaque typedefs that prevent accidental conversion
// Requirements:
// - Create OPAQUE_TYPEDEF macro
// - Generate wrapper struct for underlying type
// - Prevent implicit conversions
// - Provide explicit conversions
// - Support arithmetic for numeric types
//
// Example usage:
//   OPAQUE_TYPEDEF(int, UserId);
//   OPAQUE_TYPEDEF(int, ProductId);
//   UserId uid{42};
//   ProductId pid{42};
//   // uid == pid;  // compilation error
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.16: Recursive Variant (AST-like structures)
// ============================================================================
// TODO: Create recursive variant for tree-like structures
// Requirements:
// - Use std::variant with recursive wrapper
// - Create Expression type: Number | Add | Multiply
// - Add and Multiply contain unique_ptr<Expression>
// - Implement eval visitor
//
// Example usage:
//   Expression expr = Add{
//       std::make_unique<Expression>(Number{5}),
//       std::make_unique<Expression>(Number{3})
//   };
//   int result = eval(expr);  // 8
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 12.17: Newtype Pattern with Operators
// ============================================================================
// TODO: Create newtype wrappers with selective operator exposure
// Requirements:
// - Create Meters, Kilograms newtypes
// - Implement appropriate operators (Meters + Meters = Meters)
// - Prevent invalid operations (Meters + Kilograms)
// - Use templates to reduce boilerplate
//
// Example usage:
//   Meters m1{100}, m2{50};
//   Meters m3 = m1 + m2;  // OK
//   // Kilograms kg{10};
//   // auto x = m1 + kg;  // compilation error
//
// YOUR CODE HERE:




} // namespace Ex12
