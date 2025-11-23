#pragma once
#include <iostream>

class IntPair{

public:
    int a {};
    int b {};

    void set(int a, int b){
        this->a = a;
        this->b = b;
    }

    void print(){
        std::cout << a << " " << b << "\n";
    }
};
