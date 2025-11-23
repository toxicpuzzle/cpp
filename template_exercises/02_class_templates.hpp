#pragma once
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <memory>

/**
 * Exercise 02: Class Templates
 *
 * Learning objectives:
 * - Create class templates with type parameters
 * - Use non-type template parameters
 * - Implement template member functions
 * - Understand template class instantiation
 */

namespace Ex02 {

// ============================================================================
// EXERCISE 2.1: Simple Array Template
// ============================================================================
// TODO: Implement a 'FixedArray' class template
// Requirements:
// - Template parameters: type T and size_t N (array size)
// - Private member: T m_data[N]
// - Constructor: default initialize the array
// - operator[]: return reference to element at index (no bounds checking)
// - size(): return N
//
// Example usage:
//   FixedArray<int, 5> arr;
//   arr[0] = 10;
//   std::cout << arr.size();  // prints 5
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 2.2: Dynamic Array Template (Simple Vector)
// ============================================================================
// TODO: Implement a 'DynamicArray' class template
// Requirements:
// - Template parameter: type T
// - Private members: T* m_data, size_t m_size, size_t m_capacity
// - Constructor: takes initial capacity (default 10)
// - Destructor: deallocate m_data
// - push_back(const T& value): add element (double capacity if needed)
// - operator[]: return reference to element at index
// - size(): return m_size
// - capacity(): return m_capacity
//
// Example usage:
//   DynamicArray<int> arr;
//   arr.push_back(5);
//   arr.push_back(10);
//   std::cout << arr[0];  // prints 5
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 2.3: Pair Template
// ============================================================================
// TODO: Implement a 'Pair' class template
// Requirements:
// - Template parameters: types T and U
// - Public members: T first, U second
// - Constructor: takes T and U values to initialize members
// - swap(): swap first and second (only if T and U are the same type)
//
// Example usage:
//   Pair<int, double> p{5, 3.14};
//   std::cout << p.first << " " << p.second;
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 2.4: Stack Template
// ============================================================================
// TODO: Implement a 'Stack' class template using a fixed-size array
// Requirements:
// - Template parameters: type T and size_t N (max capacity)
// - Private members: T m_data[N], size_t m_top
// - Constructor: initialize m_top to 0
// - push(const T& value): add to top (throw if full)
// - pop(): remove from top (throw if empty)
// - top(): return reference to top element (throw if empty)
// - empty(): return true if stack is empty
// - full(): return true if stack is full
// - size(): return number of elements
//
// Example usage:
//   Stack<int, 100> stack;
//   stack.push(5);
//   stack.push(10);
//   std::cout << stack.top();  // prints 10
//   stack.pop();
//   std::cout << stack.top();  // prints 5
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 2.5: Template with Member Function Template
// ============================================================================
// TODO: Implement a 'Container' class template with a templated member function
// Requirements:
// - Class template parameter: type T
// - Private member: T m_value
// - Constructor: takes T value
// - getValue(): return m_value
// - template<typename U> convertTo(): convert m_value to type U using static_cast
//
// Example usage:
//   Container<int> c{42};
//   auto d = c.convertTo<double>();  // returns 42.0
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 2.6: Template with Initializer List
// ============================================================================
// TODO: Implement a 'SmallVector' class template
// Requirements:
// - Template parameter: type T
// - Private members: T* m_data, size_t m_size
// - Constructor: takes std::initializer_list<T>
// - Destructor: deallocate m_data
// - Copy constructor: deep copy
// - operator[]: return reference to element at index
// - size(): return m_size
// - begin() and end(): return T* for range-based for loops
//
// Example usage:
//   SmallVector<int> vec{1, 2, 3, 4, 5};
//   for (auto val : vec) {
//       std::cout << val << " ";
//   }
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 2.7: Nested Template Class
// ============================================================================
// TODO: Implement a 'BinaryTree' class template with a nested Node struct
// Requirements:
// - Template parameter: type T
// - Nested struct Node: contains T data, Node* left, Node* right
// - Private member: Node* m_root
// - Constructor: initialize m_root to nullptr
// - insertRoot(const T& value): create root node if null
// - getRoot(): return m_root
//
// Example usage:
//   BinaryTree<int> tree;
//   tree.insertRoot(10);
//   auto root = tree.getRoot();
//
// YOUR CODE HERE:





// ============================================================================
// EXERCISE 2.8: Template with Static Member
// ============================================================================
// TODO: Implement a 'Counter' class template
// Requirements:
// - Template parameter: type T
// - Private static member: size_t s_count (counts instances)
// - Constructor: increment s_count
// - Destructor: decrement s_count
// - static getCount(): return s_count
// - Note: You'll need to define the static member outside the class
//
// Example usage:
//   Counter<int> c1, c2;
//   std::cout << Counter<int>::getCount();  // prints 2
//
// YOUR CODE HERE:





} // namespace Ex02
