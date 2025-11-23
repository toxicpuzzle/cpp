#pragma once
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <mutex>

/**
 * Exercise 10: Essential C++ Idioms
 *
 * Learning objectives:
 * - Master RAII (Resource Acquisition Is Initialization)
 * - Implement Rule of Zero/Three/Five correctly
 * - Use Copy-and-Swap idiom
 * - Understand Named Parameter Idiom
 * - Apply Non-Virtual Interface (NVI) pattern
 * - Use Strong Type idiom
 * - Implement Scope Guard pattern
 */

namespace Ex10 {

// ============================================================================
// EXERCISE 10.1: RAII - Resource Acquisition Is Initialization
// ============================================================================
// TODO: Implement RAII wrappers for various resources
// Requirements:
// - Create FileHandle class that manages FILE* resource
// - Constructor opens file, destructor closes it
// - Disable copy, enable move
// - Add isOpen() method
// - Add read/write methods
//
// Example usage:
//   {
//       FileHandle file("data.txt", "r");
//       // file is automatically closed when going out of scope
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.2: Rule of Zero
// ============================================================================
// TODO: Demonstrate Rule of Zero with smart pointers
// Requirements:
// - Create DataContainer that manages dynamic data
// - Use std::unique_ptr or std::vector internally
// - Do NOT define copy/move/destructor (rely on defaults)
// - Add methods to access and modify data
//
// Rule of Zero: If you can use standard containers and smart pointers,
// you don't need to define special member functions.
//
// Example usage:
//   DataContainer dc;
//   dc.addValue(42);
//   int val = dc.getValue(0);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.3: Rule of Three
// ============================================================================
// TODO: Implement a class following Rule of Three
// Requirements:
// - Create Array class that manages raw int array
// - Implement: destructor, copy constructor, copy assignment
// - Properly handle deep copying
// - Demonstrate why all three are needed
//
// Rule of Three: If you define one of (destructor, copy constructor,
// copy assignment), you probably need to define all three.
//
// Example usage:
//   Array a1(10);
//   Array a2 = a1;  // copy constructor
//   a1 = a2;        // copy assignment
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.4: Rule of Five
// ============================================================================
// TODO: Implement a class following Rule of Five
// Requirements:
// - Create Buffer class that manages raw memory
// - Implement: destructor, copy constructor, copy assignment,
//              move constructor, move assignment
// - Use std::exchange for move operations
// - Make move operations noexcept
//
// Rule of Five: In C++11+, also define move constructor and move assignment.
//
// Example usage:
//   Buffer b1(1024);
//   Buffer b2 = std::move(b1);  // move constructor
//   b1 = std::move(b2);         // move assignment
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.5: Copy-and-Swap Idiom
// ============================================================================
// TODO: Implement copy-and-swap idiom for safe assignment
// Requirements:
// - Create String class that manages char array
// - Implement swap() method (noexcept)
// - Implement copy constructor
// - Implement assignment using copy-and-swap
// - This provides strong exception guarantee
//
// Example usage:
//   String s1("Hello");
//   String s2("World");
//   s1 = s2;  // uses copy-and-swap
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.6: Named Parameter Idiom
// ============================================================================
// TODO: Implement Named Parameter Idiom for configurable objects
// Requirements:
// - Create HttpRequest class with many optional parameters
// - Add fluent setters: setUrl, setMethod, setTimeout, setHeaders, etc.
// - Each setter returns *this for chaining
// - Add build() or execute() method
//
// Example usage:
//   HttpRequest req;
//   req.setUrl("http://example.com")
//      .setMethod("POST")
//      .setTimeout(30)
//      .addHeader("Content-Type", "application/json")
//      .execute();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.7: Non-Virtual Interface (NVI) Pattern
// ============================================================================
// TODO: Implement NVI pattern for template method
// Requirements:
// - Create base class Widget with public non-virtual interface
// - Provide private virtual methods for customization
// - Derived classes override private virtual methods
// - Public interface enforces pre/post conditions
//
// Example usage:
//   class Button : public Widget {
//       void drawImpl() override { ... }
//   };
//   Button b;
//   b.draw();  // calls public non-virtual, which calls private virtual
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.8: Strong Type Idiom
// ============================================================================
// TODO: Create strong type wrappers to prevent mixing incompatible types
// Requirements:
// - Create template StrongType<T, Tag> wrapper
// - Wrap primitive types to create distinct types
// - Define UserId, ProductId as strong types
// - Prevent implicit conversion between them
// - Provide explicit get() method
//
// Example usage:
//   UserId userId{42};
//   ProductId productId{42};
//   // userId == productId;  // compilation error!
//   int id = userId.get();   // explicit access
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.9: Scope Guard Pattern
// ============================================================================
// TODO: Implement a scope guard for automatic cleanup
// Requirements:
// - Create ScopeGuard class that takes a lambda
// - Execute the lambda in destructor
// - Add dismiss() method to cancel execution
// - Make it moveable but not copyable
//
// Example usage:
//   {
//       ScopeGuard guard([]{ cleanup(); });
//       doWork();
//       // cleanup() called automatically
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.10: Executing Around Idiom (Lock Guard Pattern)
// ============================================================================
// TODO: Implement custom lock guard with additional features
// Requirements:
// - Create MutexGuard that locks/unlocks mutex
// - Add timing to measure how long lock is held
// - Add logging of lock acquisition/release
// - Make it non-copyable and non-moveable
//
// Example usage:
//   std::mutex m;
//   {
//       MutexGuard guard(m);
//       // critical section
//   }  // mutex unlocked, time logged
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.11: Return Value Optimization (RVO) Awareness
// ============================================================================
// TODO: Write code that demonstrates RVO and NRVO
// Requirements:
// - Create HeavyObject class with visible copy/move operations
// - Implement functions that return by value
// - Demonstrate when RVO applies (Named RVO and unnamed RVO)
// - Show how to enable RVO (single return path, no std::move)
//
// Example usage:
//   HeavyObject obj = createHeavyObject();  // RVO applies, no copy/move
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.12: Attorney-Client Idiom
// ============================================================================
// TODO: Implement Attorney-Client for controlled friendship
// Requirements:
// - Create Client class with private members
// - Create Attorney class that provides limited access to Client private
// - Attorney is friend of Client
// - Third party (Worker) accesses Client through Attorney
// - This provides granular access control
//
// Example usage:
//   Client c;
//   Worker w;
//   w.doWorkOn(c);  // uses Attorney to access specific Client private methods
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.13: Passkey Idiom
// ============================================================================
// TODO: Implement Passkey idiom for controlled access
// Requirements:
// - Create Key class (empty, private constructor)
// - Create Locked class with method requiring Key
// - Create Friend class that is friend of Key
// - Only Friend can call Locked's protected methods
//
// This is more fine-grained than friendship.
//
// Example usage:
//   Locked locked;
//   Friend f;
//   f.accessLocked(locked);  // works because Friend can create Key
//   // Direct access fails: locked.protectedMethod(Key{});  // Key() is private
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.14: Prefer Non-Member Non-Friend Functions
// ============================================================================
// TODO: Demonstrate why non-member functions increase encapsulation
// Requirements:
// - Create Rectangle class with minimal public interface
// - Implement member functions: width(), height(), area()
// - Implement non-member functions: perimeter(), diagonal(), scale()
// - Show that non-member functions only access public interface
//
// Principle: Functions that can be implemented using public interface
// should be non-members for better encapsulation.
//
// Example usage:
//   Rectangle r{10, 20};
//   double p = perimeter(r);  // non-member
//   double a = r.area();      // member
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 10.15: Barton-Nackman Trick (Restricted Template Expansion)
// ============================================================================
// TODO: Use friend functions in template classes for better overload resolution
// Requirements:
// - Create template class Array<T>
// - Define operator== as friend function inside class
// - This limits where the operator is found (ADL only)
// - Prevents unwanted template instantiations
//
// Example usage:
//   Array<int> a1, a2;
//   bool eq = (a1 == a2);  // finds friend operator via ADL
//
// YOUR CODE HERE:




} // namespace Ex10
