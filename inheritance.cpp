#include <iostream>
class Animal{
public:
    void say(){ // function not overridable by child classes!
        std::cout << "I am saying as an animal!\n";
    }

    virtual void print(){ // non-pure virtual but overridable!
        std::cout << "I am an animal!\n";
    };

    virtual void description() = 0; // pure virtual i.e. abstract function
};

class Cat: public Animal{
    virtual void print(){
        std::cout << "I am a cat\n";
    }

    virtual void description(){
        std::cout << "I can purr\n";
    }

    void say(){ // function does not override parents!
        std::cout << "I should not be able to say this as a cat\n";
    }
};

void takeAnimalLValueReference(Animal& animal){
    animal.description();
}

int main(int argc, char const *argv[])
{
    /* code */
    Animal&& animal = Cat{}; //&& to allow storage of r-value inside l-value
    animal.say(); // I am saying as an animal 
    animal.print(); // I am a cat (override successful)
    animal.description(); // I can purr (override of abstract/pure function successful);

    Cat a = Cat{};
    takeAnimalLValueReference(a);

    //! Why does this work, isn't animal an r-value?
    // Because animal itself is a l-value.
    takeAnimalLValueReference(animal); 

    return 0;
}
