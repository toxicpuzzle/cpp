#include <iostream>

class Ball{

public:
    std::string m_color{"black"}; // Non-static member initialisation
    float m_radius{10.0};

public:

// Without default params
    // Ball(std::string m_color){
    //     this->m_color = m_color;
    // }

    // Ball(float m_radius){
    //     this->m_radius = m_radius;
    // }

    // Ball(std::string m_color, float m_radius){
    //     this->m_color = m_color;
    //     this->m_radius = m_radius;
    // }

    // Ball(){

    // }

// With default paramas
    // use string_view so that param is not copied, so you have read only access to existing string
    // Ball(std::string_view m_color = "black", float m_radius = 10.0){
    //     this->m_color = m_color;
    //     this->m_radius = m_radius;
    // }

    // Ball(float m_radius){
    //     this->m_radius = m_radius;
    // }

    void print(){
        std::cout << "color: " << m_color << ", radius: " << m_radius << "\n"; 
    }

//  With Non-static member initialisation and member initialiser lists
    // Ball() = default; // Default constructor -> if no param -> will use default nsm values

    // Ball(std::string_view color): m_color{ color }{} -> other value will still be default
    
    // Ball(float radius) : m_radius{ radius }{}

    // Ball(std::string_view color, float radius): m_color{color}, m_radius{radius}{}

//  Delegating constructors - constructors can either 1. Delegate via mils to other constructors or 2. MILs Initialise vars itself not both
//  but you can have non-constructor member functions inside constructor that delegates (i.e. func runs after delegated constructor runs)
    Ball() = default;

    Ball(std::string_view m_color, float m_radius): m_color{m_color}, m_radius{m_radius}{
    }

    Ball(std::string_view m_color) : Ball(m_color, 0){}

    Ball(float radius) : Ball("red", 1){
    }

    // Not allowed, cannot delegate mils to other constructors + mil initialise vars itself
    // Ball(float radius) : Ball("red", 1), m_color{"red"}{
    // }
};

int main()
{
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}