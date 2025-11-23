#pragma once
#include <iostream>
#include <string>
#include <map>

/**
 * Exercise 08: X Macros Pattern
 *
 * Learning objectives:
 * - Understand X Macros for code generation
 * - Use preprocessor to eliminate repetitive code
 * - Apply X Macros to enums, strings, and dispatch tables
 * - Combine X Macros with modern C++ features
 *
 * The X Macro pattern uses the preprocessor to generate code from a single
 * list definition, reducing duplication and keeping related data synchronized.
 */

namespace Ex08 {

// ============================================================================
// EXERCISE 8.1: Basic X Macro - Enum and String Conversion
// ============================================================================
// TODO: Use X Macros to define an enum and automatic string conversion
// Requirements:
// - Define COLOR_LIST macro with: RED, GREEN, BLUE, YELLOW
// - Generate enum Color using the list
// - Generate colorToString function using the list
// - Generate stringToColor function using the list
//
// Pattern:
//   #define COLOR_LIST \
//       X(RED) \
//       X(GREEN) \
//       X(BLUE) \
//       X(YELLOW)
//
// Example usage:
//   Color c = Color::RED;
//   std::string s = colorToString(c);  // "RED"
//   Color c2 = stringToColor("GREEN"); // Color::GREEN
//
// YOUR CODE HERE:
// Step 1: Define the list




// Step 2: Generate the enum



// Step 3: Generate colorToString



// Step 4: Generate stringToColor




// ============================================================================
// EXERCISE 8.2: X Macros with Multiple Arguments
// ============================================================================
// TODO: Use X Macros with multiple arguments for error codes
// Requirements:
// - Define ERROR_LIST with: code number, name, description
// - Generate enum ErrorCode
// - Generate getErrorMessage(ErrorCode) function
// - Generate getErrorName(ErrorCode) function
//
// List format:
//   #define ERROR_LIST \
//       X(0, SUCCESS, "Operation completed successfully") \
//       X(1, FILE_NOT_FOUND, "The specified file was not found") \
//       X(2, PERMISSION_DENIED, "Permission denied") \
//       X(3, INVALID_ARGUMENT, "Invalid argument provided")
//
// Example usage:
//   ErrorCode err = ErrorCode::FILE_NOT_FOUND;
//   std::string msg = getErrorMessage(err);  // "The specified file was not found"
//   std::string name = getErrorName(err);    // "FILE_NOT_FOUND"
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 8.3: X Macros for Switch Statement Generation
// ============================================================================
// TODO: Generate a comprehensive switch statement using X Macros
// Requirements:
// - Define COMMAND_LIST with: command names
// - Generate enum Command
// - Generate executeCommand(Command) that prints different messages
// - Use X Macro to generate all switch cases
//
// Commands: START, STOP, PAUSE, RESUME, RESET
//
// Example usage:
//   executeCommand(Command::START);  // prints "Executing START command"
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 8.4: X Macros for Struct Member Declaration
// ============================================================================
// TODO: Use X Macros to declare struct members and generate serialization
// Requirements:
// - Define PERSON_FIELDS with: type and name for each field
// - Generate struct Person with all fields
// - Generate toString() method
// - Generate fromString() method (simplified)
//
// Fields:
//   X(std::string, name)
//   X(int, age)
//   X(std::string, email)
//   X(double, salary)
//
// Example usage:
//   Person p{"John", 30, "john@example.com", 50000.0};
//   std::string s = p.toString();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 8.5: X Macros for Function Dispatch Table
// ============================================================================
// TODO: Create a dispatch table using X Macros
// Requirements:
// - Define OPERATION_LIST with math operations: ADD, SUB, MUL, DIV, MOD
// - Generate enum Operation
// - Generate calculate(Operation, int, int) using a dispatch approach
// - Use X Macro to build the dispatch logic
//
// Example usage:
//   int result = calculate(Operation::ADD, 5, 3);  // 8
//   int result2 = calculate(Operation::MUL, 5, 3); // 15
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 8.6: X Macros for Class Registration
// ============================================================================
// TODO: Use X Macros to register classes in a factory
// Requirements:
// - Define SHAPE_LIST with: Circle, Rectangle, Triangle
// - Generate enum ShapeType
// - Create base class Shape with virtual draw()
// - Create derived classes for each shape
// - Generate factory function createShape(ShapeType)
//
// Example usage:
//   Shape* s = createShape(ShapeType::Circle);
//   s->draw();  // prints "Drawing Circle"
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 8.7: X Macros for Bit Flags
// ============================================================================
// TODO: Use X Macros to define bit flags and operations
// Requirements:
// - Define FLAG_LIST with: READ, WRITE, EXECUTE, DELETE
// - Generate enum with bit positions
// - Generate hasFlag(flags, flag) function
// - Generate setFlag(flags, flag) function
// - Generate clearFlag(flags, flag) function
// - Generate flagsToString(flags) function
//
// Example usage:
//   unsigned int flags = 0;
//   setFlag(flags, FLAG_READ);
//   setFlag(flags, FLAG_WRITE);
//   bool can = hasFlag(flags, FLAG_READ);  // true
//   std::string s = flagsToString(flags);  // "READ | WRITE"
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 8.8: X Macros with Include Files
// ============================================================================
// TODO: Use X Macros with external file inclusion
// Requirements:
// - Create a pattern where the list is in a separate file
// - Define CONFIG_PARAMS in a way that can be included multiple times
// - Generate struct Config with all parameters
// - Generate getter methods
// - Generate setter methods with validation
//
// Config parameters:
//   X(int, maxConnections, 100, 1, 1000)
//   X(int, timeout, 30, 1, 300)
//   X(bool, enableLogging, true, false, true)
//   X(std::string, serverName, "localhost", "", "")
//
// Note: For this exercise, define the list inline but show how it could
//       be included from a file using #include "config_params.def"
//
// Example usage:
//   Config cfg;
//   cfg.setMaxConnections(500);
//   int max = cfg.getMaxConnections();  // 500
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 8.9: X Macros for State Machine
// ============================================================================
// TODO: Use X Macros to define a state machine
// Requirements:
// - Define STATE_LIST with: IDLE, RUNNING, PAUSED, STOPPED, ERROR
// - Generate enum State
// - Generate getStateName(State) function
// - Generate isValidTransition(State from, State to) function
// - Define valid transitions using X Macros
//
// Valid transitions:
//   IDLE -> RUNNING
//   RUNNING -> PAUSED, STOPPED, ERROR
//   PAUSED -> RUNNING, STOPPED
//   STOPPED -> IDLE
//   ERROR -> IDLE
//
// Example usage:
//   bool valid = isValidTransition(State::IDLE, State::RUNNING);  // true
//   bool invalid = isValidTransition(State::IDLE, State::PAUSED); // false
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 8.10: X Macros for Test Case Generation
// ============================================================================
// TODO: Use X Macros to generate test cases
// Requirements:
// - Define TEST_CASES with: input1, input2, expected result, operation name
// - Generate test functions for each case
// - Generate a runAllTests() function
// - Print pass/fail for each test
//
// Test cases for addition:
//   X(2, 3, 5, "simple_add")
//   X(0, 0, 0, "zero_add")
//   X(-5, 5, 0, "negative_add")
//   X(100, 200, 300, "large_add")
//
// Example usage:
//   runAllTests();  // runs all tests and prints results
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 8.11: X Macros for Reflection-like Behavior
// ============================================================================
// TODO: Create a reflection system using X Macros
// Requirements:
// - Define REFLECTED_CLASS with class name and member list
// - Generate the class with all members
// - Generate getMemberCount() static method
// - Generate getMemberName(index) static method
// - Generate getMemberType(index) static method
// - Generate serialize() method that outputs all members
//
// Example:
//   class User {
//     - std::string username
//     - int userId
//     - bool isActive
//   }
//
// Example usage:
//   User u{"john", 42, true};
//   std::cout << User::getMemberCount();      // 3
//   std::cout << User::getMemberName(0);      // "username"
//   std::string json = u.serialize();         // {"username":"john",...}
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 8.12: Combining X Macros with constexpr
// ============================================================================
// TODO: Combine X Macros with modern C++ constexpr
// Requirements:
// - Define CONSTANT_LIST with: name and value
// - Generate constexpr variables using X Macros
// - Generate compile-time lookup function
// - Generate array of all constants
//
// Constants:
//   X(PI, 3.14159265359)
//   X(E, 2.71828182846)
//   X(GOLDEN_RATIO, 1.61803398875)
//   X(SQRT2, 1.41421356237)
//
// Example usage:
//   constexpr double pi = Constants::PI;
//   constexpr auto arr = Constants::getAll();  // array of all constants
//
// YOUR CODE HERE:




} // namespace Ex08
