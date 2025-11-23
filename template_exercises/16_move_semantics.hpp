#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <type_traits>

/**
 * Exercise 16: Modern Move Semantics Deep Dive
 *
 * Learning objectives:
 * - Master rvalue references and move semantics
 * - Understand perfect forwarding and universal references
 * - Implement move constructors and move assignment
 * - Learn when copy elision happens (RVO, NRVO)
 * - Use std::move and std::forward correctly
 * - Apply noexcept for move operations
 * - Build move-only types
 */

namespace Ex16 {

// ============================================================================
// EXERCISE 16.1: Basic Move Constructor and Move Assignment
// ============================================================================
// TODO: Implement move semantics for a Buffer class
// Requirements:
// - Buffer class manages dynamically allocated array
// - Implement move constructor
// - Implement move assignment operator
// - Leave moved-from object in valid but unspecified state
// - Mark as noexcept
//
// Example usage:
//   Buffer b1(100);
//   Buffer b2 = std::move(b1);  // Move, not copy
//   b1 is now empty/null
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.2: Rule of Five
// ============================================================================
// TODO: Implement all five special member functions
// Requirements:
// - Create String class with char* data
// - Destructor
// - Copy constructor
// - Copy assignment operator
// - Move constructor (noexcept)
// - Move assignment operator (noexcept)
//
// Example usage:
//   String s1("hello");
//   String s2 = s1;           // Copy
//   String s3 = std::move(s1);  // Move
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.3: Move-Only Type (Unique Resource)
// ============================================================================
// TODO: Create a move-only type that cannot be copied
// Requirements:
// - FileHandle class wraps FILE*
// - Delete copy constructor and copy assignment
// - Implement move constructor and move assignment
// - RAII: close file in destructor
// - Can be stored in std::vector
//
// Example usage:
//   FileHandle file("data.txt");
//   FileHandle file2 = std::move(file);  // OK
//   // FileHandle file3 = file2;  // Error: deleted
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.4: Perfect Forwarding with std::forward
// ============================================================================
// TODO: Implement perfect forwarding wrapper
// Requirements:
// - Create factory function that forwards arguments
// - Use template<typename... Args>
// - Use std::forward to preserve lvalue/rvalue-ness
// - Construct object with perfectly forwarded args
//
// Example usage:
//   auto ptr = makeUnique<std::string>(5, 'x');  // "xxxxx"
//   // Forwards 5 and 'x' to std::string constructor
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.5: Universal References and Reference Collapsing
// ============================================================================
// TODO: Demonstrate universal references (forwarding references)
// Requirements:
// - Create function template with T&& parameter
// - Show it binds to both lvalues and rvalues
// - Explain reference collapsing rules
// - Use std::is_lvalue_reference_v and std::is_rvalue_reference_v
//
// Example usage:
//   int x = 42;
//   processValue(x);        // T = int&, T&& = int& (lvalue reference)
//   processValue(42);       // T = int, T&& = int&& (rvalue reference)
//   processValue(std::move(x));  // T = int, T&& = int&&
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.6: std::move Implementation
// ============================================================================
// TODO: Implement your own version of std::move
// Requirements:
// - Cast lvalue to rvalue reference
// - Use static_cast<T&&>
// - Use std::remove_reference
// - Unconditional cast
//
// Example usage:
//   std::string s = "hello";
//   std::string s2 = myMove(s);  // Calls move constructor
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.7: Return Value Optimization (RVO) vs Move
// ============================================================================
// TODO: Demonstrate RVO, NRVO, and when moves happen
// Requirements:
// - Create class that logs copy/move operations
// - Show RVO: return by value, no move
// - Show NRVO: named return value optimization
// - Show when std::move is needed
// - Show when std::move is pessimization
//
// Example usage:
//   Widget createWidget() { return Widget(); }  // RVO, no move
//   Widget w = createWidget();  // No copy, no move
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.8: Conditional noexcept
// ============================================================================
// TODO: Use conditional noexcept based on member types
// Requirements:
// - Container class with template parameter T
// - Move constructor noexcept if T's move is noexcept
// - Use noexcept(noexcept(...)) idiom
// - std::is_nothrow_move_constructible
//
// Example usage:
//   template<typename T>
//   class Container {
//       Container(Container&&) noexcept(std::is_nothrow_move_constructible_v<T>);
//   };
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.9: Move and Exception Safety
// ============================================================================
// TODO: Implement strong exception guarantee with move
// Requirements:
// - Vector-like class with push_back
// - Reallocate when capacity exceeded
// - Use move if noexcept, otherwise copy
// - Show why std::move_if_noexcept exists
//
// Example usage:
//   MyVector<Widget> vec;
//   vec.push_back(widget);  // Uses move if safe
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.10: Moving from *this
// ============================================================================
// TODO: Implement method that moves from object itself
// Requirements:
// - Create Builder pattern class
// - build() method consumes object (moves from *this)
// - Return unique_ptr to built object
// - Mark method with && ref-qualifier
//
// Example usage:
//   Widget w = WidgetBuilder().setX(5).setY(10).build();
//   // build() is rvalue-qualified, moves from builder
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.11: Ref-Qualifiers for Member Functions
// ============================================================================
// TODO: Use ref-qualifiers to control method availability
// Requirements:
// - Create class with &-qualified and &&-qualified methods
// - & qualifier: only callable on lvalues
// - && qualifier: only callable on rvalues
// - Demonstrate with data() method
//
// Example usage:
//   class String {
//       const char* data() const & { return m_data; }
//       char* data() && { return m_data; }  // Can steal from temporary
//   };
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.12: Implementing std::exchange
// ============================================================================
// TODO: Implement std::exchange utility
// Requirements:
// - Replaces value and returns old value
// - Useful in move assignment operators
// - Template function
// - Use std::move internally
//
// Example usage:
//   int x = 5;
//   int old = myExchange(x, 10);  // x = 10, returns 5
//   // Useful: m_data = myExchange(other.m_data, nullptr);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.13: Move Semantics for Containers
// ============================================================================
// TODO: Implement move operations for custom vector
// Requirements:
// - SimpleVector class with dynamic array
// - Move constructor transfers ownership
// - Move assignment with self-assignment check
// - Proper cleanup of moved-from state
//
// Example usage:
//   SimpleVector<int> v1 = {1, 2, 3};
//   SimpleVector<int> v2 = std::move(v1);  // v1 is now empty
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.14: Forwarding in Variadic Templates
// ============================================================================
// TODO: Combine perfect forwarding with variadic templates
// Requirements:
// - emplace_back-like function
// - Construct object in-place
// - Forward all arguments perfectly
// - Use placement new
//
// Example usage:
//   template<typename... Args>
//   void emplace(Args&&... args) {
//       new (ptr) T(std::forward<Args>(args)...);
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.15: Move Semantics with Inheritance
// ============================================================================
// TODO: Implement move operations in class hierarchy
// Requirements:
// - Base class with move operations
// - Derived class with move operations
// - Properly call base class move constructor
// - Handle additional derived class members
//
// Example usage:
//   Derived d1;
//   Derived d2 = std::move(d1);  // Moves both base and derived parts
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.16: Detecting Moved-From State
// ============================================================================
// TODO: Add debug support for detecting use of moved-from objects
// Requirements:
// - Add flag to track if object was moved-from
// - Assert if methods called on moved-from object
// - Only in debug builds (#ifdef NDEBUG)
// - Reset flag on assignment
//
// Example usage:
//   Widget w1;
//   Widget w2 = std::move(w1);
//   w1.doSomething();  // Asserts in debug build
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.17: Move Semantics for Smart Pointers
// ============================================================================
// TODO: Implement simple unique_ptr-like class
// Requirements:
// - Owns pointer exclusively
// - Move constructor and move assignment
// - Deleted copy operations
// - get(), release(), reset() methods
// - operator*, operator-> overloads
//
// Example usage:
//   UniquePtr<Widget> ptr1 = makeUnique<Widget>();
//   UniquePtr<Widget> ptr2 = std::move(ptr1);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 16.18: Copy Elision and Guaranteed Copy Elision (C++17)
// ============================================================================
// TODO: Demonstrate guaranteed copy elision scenarios
// Requirements:
// - Show prvalue materialization
// - Return unmaterialized temporary
// - Pass temporary to function
// - Show move is never called
//
// Example usage:
//   Widget w = Widget();  // C++17: no move, guaranteed
//   void func(Widget);
//   func(Widget());  // C++17: no move
//
// YOUR CODE HERE:




} // namespace Ex16
