#include <memory>
#include <iostream>

class Object{
public:
    void print(){
        std::cout << "Hey I'm an object!\n";
    }

    Object(){
        std::cout << "Object created!\n";
    }

    ~Object(){
        std::cout << "Object deleted!\n";
    }
};

std::shared_ptr<Object> factory(){
    std::shared_ptr<Object> obj = std::make_shared<Object>();
    return obj;
}

// Object& badFactory(){
//     Object obj{};
//     return obj; // Fails as you are returning reference to stack object which will go out of scope after return
// }

int main(){
    // Shared pointers

    std::shared_ptr<int> intptr = std::make_shared<int>(5); // +1 owner PREFERRED WAY to avoid issues if constructor fails.
    std::cout << intptr << "\n"; // Prints same address as below
    std::cout << intptr.get() << "\n"; // Prints same address as above
    std::cout << *intptr << "\n";    

    // Shared ptr - allow usto get underlying raw pointer https://stackoverflow.com/questions/24097267/calling-shared-ptr-get-vs-copy-initialization-whats-the-difference
    [[maybe_unused]] auto copy = intptr; // +1 owner because copy constructor of sp is called
    [[maybe_unused]] int* notACopy = intptr.get(); // copy of raw pointer does not activate copy constructor (bad usually)
    std::cout << "int pointer has " << intptr.use_count() << "owners " << "\n";

    // Unique pointers

    // std::unique_ptr<int[]> unique = new int[20]; // Fail cannot use new keyword as unique has EXPLICIT constructor i.e. no implicit conversion from (int*) to unique_ptr allowed
    // std::unique_ptr<int> abc = 10; // Fail as well
    std::unique_ptr<int[]> unique{new int[20]};
    // auto another = unique; // Fail - cannot use copy constructor for unique pointers

    auto obj = factory(); 
    obj->print(); // works as heap allocated

    // auto badObj = badFactory();
    // badObj.print(); // Fails as not heap allocated

    obj = factory(); // causes initial obj to go out of scope - i.e. initial obj will call ~Object causing "Object deleted" message.
    std::cout << "Main still in scope before this point\n";

    // new obj gets deallocated at end of scope 
}