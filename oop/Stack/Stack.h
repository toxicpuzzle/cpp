#pragma once
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
        gid++;
    }

    ~Stack(){
    }

    void print(){
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
        return array[--size];
    }

    int getSize() const { return size; }

    int get(int index) const {
        assert(index >= 0 && index < size);
        return array[index];
    }
};

// Initialize static member
int Stack::gid = 0;
