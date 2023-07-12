#include <iostream>
#include <cstdio>
#include <cassert>

class Stack{

    static int gid;
    int size{0};
    int array[10]{};
    int id{};

    void reset(){
        size = 0;
    }

public:

    Stack(){
        this->id = gid;
        std::cout << "constructing stack..." << this->id << "\n";
        gid++;
    }

    ~Stack(){
        std::cout << "destructing stack..." << this->id << " \n";
    }

    void print(){
        // auto keyword is used for type inferencing at compile time i.e. gets replaced
        std::cout << "(";
        for (int i = 0; i < size; i++){
            std::cout << " " << array[i];
        }   
        std::cout << " )\n";
    }

    bool push(int value){
        if (size == 10) return false;
        array[size++] = value;
        return true;
    }

    int pop(){
        assert((size > 0) && "failed to pass assertion");
        return array[size--];
    }


};

int Stack::gid = 0; // Initialise static member to be equal to 0 in this file i.e. not like in java where static means globally for all usages of class

int main()
{
    // Allocation of object here occurs on the stack
	Stack stack{};
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

    // Allocation occurs on the heap because of new keyword
    Stack* heapStack{ new Stack{} };
    heapStack->print();
    heapStack->push(1);
    heapStack->print();

    // stack (first one) is automatically destructed as it goes out of scope (no need to call delete)
    // CPP impelements RAII (Resource Acquisition is Initialisation) via constructs w/ destructors

    // heapStack is on the heap so we don't know if it goes out of scope (stack 0 i.e. stack stack is deleted after return)
    delete heapStack;

    // You only need destructors for complex heap objects e.g. files, dynamic arrays. for primitives you don't need.

	return 0;
}