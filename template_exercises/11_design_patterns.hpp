#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <functional>
#include <string>

/**
 * Exercise 11: Design Patterns in Modern C++
 *
 * Learning objectives:
 * - Implement classic Gang of Four patterns with modern C++
 * - Use smart pointers, lambdas, and move semantics
 * - Apply patterns to real-world scenarios
 * - Understand when and why to use each pattern
 */

namespace Ex11 {

// ============================================================================
// EXERCISE 11.1: Singleton Pattern (Thread-Safe, Modern)
// ============================================================================
// TODO: Implement a thread-safe singleton using C++11 magic statics
// Requirements:
// - Create Logger class as singleton
// - Use static local variable (guaranteed thread-safe in C++11+)
// - Delete copy and move constructors
// - Add log() method
// - Demonstrate Meyer's Singleton pattern
//
// Example usage:
//   Logger::getInstance().log("Hello");
//   // No way to create multiple instances
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.2: Factory Pattern with Unique Pointers
// ============================================================================
// TODO: Implement factory pattern returning unique_ptr
// Requirements:
// - Create Animal base class with virtual speak()
// - Create Dog, Cat, Bird derived classes
// - Create AnimalFactory with createAnimal(type) method
// - Return std::unique_ptr<Animal>
//
// Example usage:
//   auto dog = AnimalFactory::createAnimal("dog");
//   dog->speak();  // "Woof!"
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.3: Abstract Factory Pattern
// ============================================================================
// TODO: Implement abstract factory for UI components
// Requirements:
// - Create Button and Checkbox abstract classes
// - Create WindowsButton, WindowsCheckbox, LinuxButton, LinuxCheckbox
// - Create GUIFactory abstract class
// - Create WindowsFactory and LinuxFactory
// - Factory methods return smart pointers
//
// Example usage:
//   std::unique_ptr<GUIFactory> factory = std::make_unique<WindowsFactory>();
//   auto button = factory->createButton();
//   button->render();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.4: Builder Pattern with Fluent Interface
// ============================================================================
// TODO: Implement builder pattern for complex objects
// Requirements:
// - Create Pizza class with many optional attributes
// - Create PizzaBuilder with fluent interface
// - Methods: setSize, addTopping, setCrust, addCheese
// - build() method returns unique_ptr<Pizza>
// - Make Pizza constructor private, builder is friend
//
// Example usage:
//   auto pizza = PizzaBuilder()
//       .setSize("large")
//       .addTopping("pepperoni")
//       .addTopping("mushrooms")
//       .setCrust("thin")
//       .build();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.5: Prototype Pattern with Clone
// ============================================================================
// TODO: Implement prototype pattern for object cloning
// Requirements:
// - Create Document base class with virtual clone()
// - Create Resume and Report derived classes
// - Implement clone() returning unique_ptr
// - Use covariant return types if possible
//
// Example usage:
//   std::unique_ptr<Document> doc1 = std::make_unique<Resume>();
//   auto doc2 = doc1->clone();  // creates copy
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.6: Observer Pattern with Modern C++
// ============================================================================
// TODO: Implement observer pattern with weak_ptr
// Requirements:
// - Create Subject class that maintains observers
// - Create Observer interface with update() method
// - Store observers as std::weak_ptr to avoid circular refs
// - Add attach(shared_ptr<Observer>), detach, notify methods
// - Auto-remove expired weak_ptrs
//
// Example usage:
//   auto subject = std::make_shared<Subject>();
//   auto obs1 = std::make_shared<ConcreteObserver>();
//   subject->attach(obs1);
//   subject->setState(42);  // notifies observers
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.7: Strategy Pattern with std::function
// ============================================================================
// TODO: Implement strategy pattern using std::function
// Requirements:
// - Create Context class that uses a strategy
// - Strategy is std::function<int(int, int)>
// - Add methods: setStrategy, executeStrategy
// - Demonstrate with different algorithms (add, multiply, subtract)
//
// Modern approach: Use std::function instead of interface/inheritance
//
// Example usage:
//   Context ctx;
//   ctx.setStrategy([](int a, int b) { return a + b; });
//   int result = ctx.executeStrategy(5, 3);  // 8
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.8: Command Pattern with Lambda Support
// ============================================================================
// TODO: Implement command pattern with modern C++
// Requirements:
// - Create Command interface with execute() and undo()
// - Create CommandInvoker that stores command history
// - Support both class-based and lambda-based commands
// - Add executeCommand, undo, redo methods
//
// Example usage:
//   CommandInvoker invoker;
//   invoker.executeCommand(std::make_unique<AddCommand>(5));
//   invoker.undo();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.9: Decorator Pattern with Smart Pointers
// ============================================================================
// TODO: Implement decorator pattern for stream processing
// Requirements:
// - Create DataSource interface with read() method
// - Create FileDataSource concrete class
// - Create decorators: EncryptionDecorator, CompressionDecorator
// - Chain decorators using unique_ptr
//
// Example usage:
//   auto source = std::make_unique<FileDataSource>("data.txt");
//   source = std::make_unique<EncryptionDecorator>(std::move(source));
//   source = std::make_unique<CompressionDecorator>(std::move(source));
//   std::string data = source->read();
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.10: Adapter Pattern
// ============================================================================
// TODO: Implement adapter pattern to wrap incompatible interface
// Requirements:
// - Create Target interface (modern interface)
// - Create Adaptee class (legacy interface)
// - Create Adapter that implements Target and wraps Adaptee
// - Use composition, not inheritance for Adaptee
//
// Example usage:
//   std::unique_ptr<Target> target = std::make_unique<Adapter>();
//   target->request();  // internally calls adaptee's specificRequest()
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.11: Visitor Pattern with Modern C++
// ============================================================================
// TODO: Implement visitor pattern for AST traversal
// Requirements:
// - Create Element interface with accept(Visitor&)
// - Create Visitor interface with visit for each concrete element
// - Create concrete elements: NumberNode, AddNode, MultiplyNode
// - Create concrete visitors: PrintVisitor, EvaluateVisitor
//
// Example usage:
//   auto expr = std::make_unique<AddNode>(...);
//   PrintVisitor printer;
//   expr->accept(printer);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.12: Template Method Pattern
// ============================================================================
// TODO: Implement template method pattern
// Requirements:
// - Create Game base class with template method play()
// - Define abstract methods: initialize, startPlay, endPlay
// - play() defines the algorithm skeleton
// - Create Chess and Football derived classes
//
// Example usage:
//   std::unique_ptr<Game> game = std::make_unique<Chess>();
//   game->play();  // calls template method
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.13: State Pattern with Unique Ownership
// ============================================================================
// TODO: Implement state pattern for TCP connection
// Requirements:
// - Create State interface with handle methods
// - Create concrete states: Closed, Listen, Established
// - Create TCPConnection that holds unique_ptr<State>
// - State transitions transfer ownership
//
// Example usage:
//   TCPConnection conn;
//   conn.open();     // transitions to Listen state
//   conn.connect();  // transitions to Established state
//   conn.close();    // transitions to Closed state
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.14: Chain of Responsibility with Unique Pointers
// ============================================================================
// TODO: Implement chain of responsibility for request handling
// Requirements:
// - Create Handler interface with handleRequest and setNext
// - Create concrete handlers: AuthHandler, LogHandler, ValidationHandler
// - Chain uses unique_ptr for ownership
// - Each handler decides to process or pass to next
//
// Example usage:
//   auto chain = std::make_unique<AuthHandler>();
//   chain->setNext(std::make_unique<LogHandler>())
//        ->setNext(std::make_unique<ValidationHandler>());
//   chain->handleRequest(request);
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.15: Type Erasure Pattern (Like std::function)
// ============================================================================
// TODO: Implement type erasure for storing heterogeneous types
// Requirements:
// - Create Any class that can store any copyable type
// - Use inheritance and templates internally
// - Provide type-safe get<T>() method
// - Throw exception if wrong type requested
//
// This is how std::any and std::function are implemented
//
// Example usage:
//   Any a = 42;
//   int x = a.get<int>();  // OK
//   // std::string s = a.get<std::string>();  // throws
//
// YOUR CODE HERE:




// ============================================================================
// EXERCISE 11.16: Monostate Pattern
// ============================================================================
// TODO: Implement monostate pattern (alternative to singleton)
// Requirements:
// - Create Configuration class where all data is static
// - Multiple instances share the same state
// - No getInstance() method needed
// - Add set/get methods for configuration values
//
// Example usage:
//   Configuration c1, c2;
//   c1.setValue("key", "value");
//   std::string v = c2.getValue("key");  // sees the same value
//
// YOUR CODE HERE:




} // namespace Ex11
