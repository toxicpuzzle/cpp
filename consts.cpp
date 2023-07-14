#include <iostream>
constexpr int factorialCompileTime(int n){ // Function returns something that MUST be evaluated at compile time
    if (n == 0) return 1;
    return n*factorialCompileTime(n-1);
}

int getRunTimeInput(){
    int x{};
    std::cin >> x; // Cannot do this in constexpr function will get (call to non constexpr function)
    return x;
}

class Fibonacci{

    int x{};
    // constexpr int y{}; // cannot have constexpr variable for class

    // const member functions - cannot modify "this" instance
    int constFunction(int x) const{
        // this->x = 0; // illegal
    }

    // classes can have constexpr functions
    constexpr int eval(int n){
        if (n == 0 || n == 1) return 1;
        return this->eval(n-1) + this->eval(n-2);
    }

    

};

int main(){
    [[maybe_unused]] constexpr int x{factorialCompileTime(10)+50}; // Ensures x is evaluated at compile time
    const int y = 10;
    // x = 10; // Failes - x is constexpr cannot be casted away
    // y = 20; // Fails - y is a const
    // [[maybe_unused]] constexpr int y{getRunTimeInput()}; // Fails because function is not constexpr
}