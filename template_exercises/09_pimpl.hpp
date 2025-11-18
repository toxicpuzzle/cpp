#pragma once
#include <memory>
#include <string>
#include <vector>

/**
 * Exercise 09: PIMPL Idiom (Pointer to Implementation)
 *
 * Learning objectives:
 * - Understand the PIMPL idiom for reducing compilation dependencies
 * - Implement PIMPL with unique_ptr and shared_ptr
 * - Handle special member functions correctly
 * - Use PIMPL for ABI stability and information hiding
 *
 * Benefits of PIMPL:
 * - Reduces compilation dependencies
 * - Hides implementation details
 * - Maintains ABI (Application Binary Interface) stability
 * - Faster compilation times for clients
 * - Separates interface from implementation
 */

namespace Ex09 {

// ============================================================================
// EXERCISE 9.1: Basic PIMPL with unique_ptr
// ============================================================================
// TODO: Implement a basic PIMPL class
// Requirements:
// - Create Widget class with PIMPL idiom
// - Use std::unique_ptr<Impl> for pImpl
// - Declare Impl struct (define in .cpp in real code)
// - Implement constructor, destructor, copy, move
// - Add methods: setName, getName, doWork
//
// For this exercise, define Impl inline, but in real code it would be in .cpp
//
// Example usage:
//   Widget w;
//   w.setName("MyWidget");
//   std::string name = w.getName();
//   w.doWork();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.2: PIMPL with Copyable Semantics
// ============================================================================
// TODO: Implement PIMPL that is copyable
// Requirements:
// - Create Person class with PIMPL
// - Make it fully copyable (deep copy)
// - Store: name, age, address (private in Impl)
// - Implement copy constructor and copy assignment
// - Implement move constructor and move assignment
//
// Example usage:
//   Person p1{"John", 30, "123 Main St"};
//   Person p2 = p1;  // deep copy
//   Person p3 = std::move(p1);  // move
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.3: PIMPL with Shared State
// ============================================================================
// TODO: Implement PIMPL using shared_ptr for shared state
// Requirements:
// - Create SharedData class with PIMPL using shared_ptr
// - Multiple instances can share the same implementation
// - Add methods to modify and query shared state
// - Implement clone() method for deep copy when needed
//
// Example usage:
//   SharedData d1;
//   d1.setValue(42);
//   SharedData d2 = d1;  // shares implementation
//   d2.setValue(100);
//   assert(d1.getValue() == 100);  // both see the change
//   SharedData d3 = d2.clone();    // deep copy
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.4: PIMPL for Resource Management
// ============================================================================
// TODO: Use PIMPL to manage complex resources
// Requirements:
// - Create Database class with PIMPL
// - Implementation manages connection, prepared statements, etc.
// - Add methods: connect, disconnect, execute, query
// - Ensure proper resource cleanup
// - Make it moveable but not copyable
//
// Example usage:
//   Database db;
//   db.connect("localhost:5432");
//   db.execute("SELECT * FROM users");
//   db.disconnect();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.5: Fast PIMPL (Small Buffer Optimization)
// ============================================================================
// TODO: Implement PIMPL with small buffer optimization
// Requirements:
// - Create FastPimpl class that avoids heap allocation for small objects
// - Use aligned_storage for small buffer
// - Fall back to unique_ptr for large objects
// - Implement size-based selection at compile time
//
// This is an advanced optimization technique to avoid heap allocation
// while maintaining the PIMPL benefits.
//
// Example usage:
//   FastPimpl<SmallImpl> fp1;  // uses stack buffer
//   FastPimpl<LargeImpl> fp2;  // uses heap
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.6: PIMPL with Virtual Methods
// ============================================================================
// TODO: Combine PIMPL with polymorphism
// Requirements:
// - Create Shape class with PIMPL
// - Implementation uses inheritance (Circle, Rectangle derive from ShapeImpl)
// - Add methods: area, perimeter, draw
// - Factory method to create different shapes
//
// Example usage:
//   auto circle = Shape::createCircle(5.0);
//   double a = circle.area();
//   circle.draw();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.7: PIMPL with Observer Pattern
// ============================================================================
// TODO: Implement PIMPL that supports observers
// Requirements:
// - Create Observable class with PIMPL
// - Store list of observers in implementation
// - Add methods: attach, detach, notify
// - Observers should not be exposed in public interface
//
// Example usage:
//   Observable subject;
//   Observer obs1, obs2;
//   subject.attach(&obs1);
//   subject.attach(&obs2);
//   subject.setValue(42);  // notifies all observers
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.8: PIMPL with Compile-Time Configuration
// ============================================================================
// TODO: Use PIMPL with template-based configuration
// Requirements:
// - Create ConfigurablePimpl<Config> template class
// - Different Impl types based on Config
// - Compile-time selection of implementation
// - No runtime overhead for configuration
//
// Example usage:
//   ConfigurablePimpl<FastConfig> fast;
//   ConfigurablePimpl<SecureConfig> secure;
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.9: PIMPL with Thread Safety
// ============================================================================
// TODO: Implement thread-safe PIMPL
// Requirements:
// - Create ThreadSafeCounter class with PIMPL
// - Use mutex in implementation to protect shared state
// - Add methods: increment, decrement, get
// - Ensure all operations are thread-safe
// - Keep mutex in implementation, not visible in interface
//
// Example usage:
//   ThreadSafeCounter counter;
//   // Multiple threads can safely call:
//   counter.increment();
//   int val = counter.get();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.10: PIMPL for Platform Abstraction
// ============================================================================
// TODO: Use PIMPL to abstract platform-specific code
// Requirements:
// - Create File class with PIMPL
// - Implementation differs based on platform (simulated here)
// - Add methods: open, close, read, write
// - Platform-specific details hidden in implementation
//
// In real code, you might have:
//   - FileImpl_Windows in file_windows.cpp
//   - FileImpl_Linux in file_linux.cpp
//
// Example usage:
//   File f;
//   f.open("data.txt");
//   std::string content = f.read();
//   f.write("Hello");
//   f.close();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.11: PIMPL with Lazy Initialization
// ============================================================================
// TODO: Implement PIMPL with lazy initialization
// Requirements:
// - Create LazyWidget class
// - Implementation is created only when first needed
// - Add isInitialized() method
// - Add methods that trigger initialization
//
// Example usage:
//   LazyWidget lw;
//   assert(!lw.isInitialized());
//   lw.doWork();  // triggers initialization
//   assert(lw.isInitialized());
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.12: PIMPL with Multiple Implementations
// ============================================================================
// TODO: PIMPL that can switch implementations at runtime
// Requirements:
// - Create Renderer class with PIMPL
// - Support multiple implementations: OpenGL, Vulkan, DirectX (simulated)
// - Add setImplementation(type) method
// - Add render() method that delegates to current implementation
//
// Example usage:
//   Renderer r;
//   r.setImplementation(RendererType::OpenGL);
//   r.render();  // uses OpenGL
//   r.setImplementation(RendererType::Vulkan);
//   r.render();  // uses Vulkan
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 9.13: PIMPL with Value Semantics (Copy-on-Write)
// ============================================================================
// TODO: Implement PIMPL with copy-on-write semantics
// Requirements:
// - Create CowString class (Copy-on-Write String)
// - Use shared_ptr for implementation
// - Share implementation until write operation
// - On write, create copy if shared (use_count > 1)
// - Add methods: append, length, c_str
//
// Example usage:
//   CowString s1("Hello");
//   CowString s2 = s1;  // shares implementation
//   s2.append(" World");  // copies before modifying
//   // s1 is still "Hello", s2 is "Hello World"
//
// YOUR CODE HERE:




} // namespace Ex09
