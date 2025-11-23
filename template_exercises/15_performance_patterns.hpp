#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <chrono>
#include <cstring>
#include <algorithm>
#include <immintrin.h>  // For SIMD intrinsics (optional)

/**
 * Exercise 15: Cache-Friendly & Performance Patterns
 *
 * Learning objectives:
 * - Understand CPU cache hierarchy and cache lines
 * - Implement data-oriented design patterns
 * - Optimize memory layout for performance
 * - Avoid false sharing in multi-threaded code
 * - Use branch prediction hints
 * - Apply SIMD concepts for vectorization
 * - Measure and analyze performance
 */

namespace Ex15 {

// ============================================================================
// EXERCISE 15.1: Array of Structures (AoS) vs Structure of Arrays (SoA)
// ============================================================================
// TODO: Compare AoS and SoA performance
// Requirements:
// - Create Particle struct with position (x,y,z) and velocity (vx,vy,vz)
// - Implement ParticleSystemAoS using std::vector<Particle>
// - Implement ParticleSystemSoA with separate arrays for x,y,z,vx,vy,vz
// - Benchmark update() that only modifies position
// - Observe cache-friendliness difference
//
// Example usage:
//   ParticleSystemSoA system(10000);
//   system.update(0.016f);  // Much faster cache access
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.2: Cache Line Awareness - Avoiding False Sharing
// ============================================================================
// TODO: Demonstrate and fix false sharing problem
// Requirements:
// - Create Counter struct with just an int counter
// - Create two adjacent counters that different threads increment
// - Show false sharing when counters share cache line
// - Fix by padding to separate cache lines (64 bytes)
// - alignas(64) or manual padding
//
// Example usage:
//   alignas(64) struct PaddedCounter { int count = 0; };
//   // Now different threads won't invalidate each other's cache
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.3: Prefetching and Sequential Access
// ============================================================================
// TODO: Optimize data access patterns for cache
// Requirements:
// - Implement matrix transposition
// - Compare row-major vs column-major access
// - Use __builtin_prefetch or _mm_prefetch hints (optional)
// - Demonstrate cache-friendly iteration
//
// Example usage:
//   Matrix m(1000, 1000);
//   transposeOptimized(m);  // Better cache usage than naive version
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.4: Branch Prediction - Likely/Unlikely Hints
// ============================================================================
// TODO: Use branch prediction hints for performance
// Requirements:
// - Implement search with [[likely]]/[[unlikely]] attributes (C++20)
// - Or use __builtin_expect for older compilers
// - Benchmark with and without hints
// - Show impact on tight loops
//
// Example usage:
//   if (value == target) [[unlikely]] {
//       // Rare case - tell compiler this is unlikely
//   }
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.5: Memory Pool Allocator
// ============================================================================
// TODO: Implement a fixed-size memory pool for fast allocation
// Requirements:
// - Pre-allocate large block of memory
// - Manage free list of blocks
// - O(1) allocation and deallocation
// - No fragmentation for fixed-size objects
// - Useful for game engines, real-time systems
//
// Example usage:
//   MemoryPool<MyObject, 1000> pool;
//   MyObject* obj = pool.allocate();
//   pool.deallocate(obj);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.6: Stack/Linear Allocator
// ============================================================================
// TODO: Implement stack-based allocator for temporary allocations
// Requirements:
// - Allocate from contiguous buffer
// - Only free in LIFO order
// - Very fast allocation (just increment pointer)
// - Perfect for per-frame allocations
// - Reset all allocations at once
//
// Example usage:
//   StackAllocator allocator(1024 * 1024);  // 1MB
//   void* ptr1 = allocator.allocate(100);
//   void* ptr2 = allocator.allocate(200);
//   allocator.reset();  // Free everything
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.7: Hot/Cold Data Separation
// ============================================================================
// TODO: Separate frequently and rarely accessed data
// Requirements:
// - Create GameObject with hot data (position, velocity) and cold data (name, id)
// - Split into GameObjectHot and GameObjectCold
// - Index-based linking between hot and cold data
// - Demonstrate cache efficiency
//
// Example usage:
//   struct GameObjectHot { vec3 pos; vec3 vel; };
//   struct GameObjectCold { std::string name; int id; };
//   // Update loop only touches hot data - better cache usage
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.8: Object Pool Pattern
// ============================================================================
// TODO: Implement object pool for reusable objects
// Requirements:
// - Pre-create pool of objects
// - acquire() returns available object
// - release() returns object to pool
// - Avoid allocation in hot path
// - Handle pool exhaustion
//
// Example usage:
//   ObjectPool<Bullet> bulletPool(100);
//   Bullet* bullet = bulletPool.acquire();
//   // Use bullet...
//   bulletPool.release(bullet);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.9: Small String Optimization (SSO)
// ============================================================================
// TODO: Implement string class with small string optimization
// Requirements:
// - Store short strings (<= 15 chars) inline
// - Use heap for longer strings
// - Union or variant for storage
// - Avoid allocation for common case
//
// Example usage:
//   SmallString s1 = "short";  // No heap allocation
//   SmallString s2 = "this is a very long string";  // Uses heap
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.10: Copy-on-Write (CoW) String
// ============================================================================
// TODO: Implement copy-on-write for strings
// Requirements:
// - Multiple strings share same buffer (reference counted)
// - Only copy when modified
// - Use shared_ptr for reference counting
// - Optimize for read-heavy workloads
//
// Example usage:
//   CoWString s1 = "hello";
//   CoWString s2 = s1;  // No copy, shares buffer
//   s2[0] = 'H';  // Now copies
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.11: Cache-Friendly Hash Table
// ============================================================================
// TODO: Implement hash table optimized for cache
// Requirements:
// - Open addressing instead of chaining
// - Linear probing or Robin Hood hashing
// - Keep data contiguous in memory
// - Better cache locality than std::unordered_map
//
// Example usage:
//   FlatHashMap<int, std::string> map;
//   map.insert(42, "answer");
//   auto* value = map.find(42);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.12: Vectorization with SIMD Concepts
// ============================================================================
// TODO: Demonstrate SIMD concepts for parallel operations
// Requirements:
// - Add two arrays element-wise
// - Compare scalar vs SIMD version
// - Use intrinsics (_mm_add_ps) or compiler auto-vectorization
// - Process 4 or 8 elements at once
// - Align data appropriately
//
// Example usage:
//   alignas(16) float a[100], b[100], result[100];
//   addArraysSIMD(a, b, result, 100);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.13: Struct Packing and Alignment
// ============================================================================
// TODO: Demonstrate impact of struct packing
// Requirements:
// - Create poorly aligned struct (lots of padding)
// - Reorder members to minimize padding
// - Use alignof, sizeof to show differences
// - Explain cache line utilization
//
// Example usage:
//   struct Bad { char c; int i; char c2; };  // sizeof = 12 (with padding)
//   struct Good { int i; char c; char c2; };  // sizeof = 8
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.14: Bit Packing for Compact Data
// ============================================================================
// TODO: Pack multiple values into single integer
// Requirements:
// - Store multiple small integers in one uint32_t
// - Bit manipulation for get/set
// - Useful for flags, compressed data
// - Trade computation for memory
//
// Example usage:
//   PackedColor color;  // Stores RGBA in 32 bits
//   color.setRed(255);  // 8 bits
//   color.setGreen(128);  // 8 bits
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.15: Benchmark Framework
// ============================================================================
// TODO: Create simple benchmark framework
// Requirements:
// - Measure execution time with high precision
// - Run multiple iterations and average
// - Prevent compiler optimizations from eliminating code
// - Report min/max/average times
//
// Example usage:
//   benchmark("myFunction", []() {
//       // Code to benchmark
//   }, 1000);  // 1000 iterations
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.16: Memory Bandwidth Test
// ============================================================================
// TODO: Measure memory bandwidth with streaming operations
// Requirements:
// - Allocate large array
// - Perform streaming read/write operations
// - Measure throughput in GB/s
// - Compare sequential vs random access
//
// Example usage:
//   measureBandwidth(1024 * 1024 * 100);  // 100MB test
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.17: Custom Allocator for STL Containers
// ============================================================================
// TODO: Implement custom allocator for std::vector
// Requirements:
// - Implement allocator interface (allocate, deallocate, construct, destroy)
// - Use memory pool or stack allocator
// - Make it work with std::vector<T, CustomAllocator<T>>
// - Track allocation statistics
//
// Example usage:
//   std::vector<int, PoolAllocator<int>> vec;
//   vec.push_back(42);  // Uses custom allocator
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 15.18: Compile-Time Computation for Performance
// ============================================================================
// TODO: Move runtime computation to compile-time
// Requirements:
// - Implement constexpr factorial
// - Implement constexpr power
// - Demonstrate compile-time lookup tables
// - Use if constexpr for optimization
//
// Example usage:
//   constexpr int f10 = factorial(10);  // Computed at compile time
//   constexpr auto lookupTable = generateTable();
//
// YOUR CODE HERE:




} // namespace Ex15
