#include <iostream>

class IntPair{

public:
    int a {};
    int b {};
    void set(int a, int b){
        // This gives you a ptr i.e. IntPair* to struct w/ functions i.e. class
        this->a = a;
        this->b = b;
    }

    void print(){
        std::cout << a << " " << b << "\n";
    }
};

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}