#ifndef OWN_TEMPLATE_H
#define OWN_TEMPLATE_H

#include <vector>
#include <iostream>
#include <unordered_map>

/**
 * Printable concept that requires type of a to be s.t. if we do os << a it is compilable
 */
template <typename T>
concept Printable = requires(std::ostream &os, T a) {
    os << a;
};

/**
 * Template to auto write funtions (like java generic method) for printing out arrays for dfferent types
 */
template <Printable T>
void printVector(const std::vector<T> &vector)
{
    std::cout << "[";
    for (T elem : vector)
    {
        std::cout << elem << ", ";
    }
    std::cout << "]";
}

template <Printable Key, Printable Value>
void printHashMap(const std::unordered_map<Key, Value>& map){
    std::cout << "Map START\n";
    // ! Requires Perceptron's << operator to take a const key, map returns const ref (so you cant just change the key manually as that would mess up hashing)
    for (const auto& [key, value]: map){
        std::cout << key << ", " << value << "\n";
    }
    std::cout << "Map END\n";
}

#endif