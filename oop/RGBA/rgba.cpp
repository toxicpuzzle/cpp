#include <iostream>

class RGBA{

    // Type aliasing - allows us to create alias for type to save typing/^maintainability 
    using Channel = std::uint8_t;

    const Channel m_red;
    const Channel m_green;
    const Channel m_blue;
    const Channel m_alpha;
    
public:


    // Using initialiser lists to initialise const variables i.e. cannot do m_red = 127 in constructor 
    RGBA(Channel m_red = 0, Channel m_green = 0, Channel m_blue = 0, Channel m_alpha = 255) :
        m_red{ m_red }, m_green{ m_green }, m_blue{ m_blue }, m_alpha{ m_alpha }
    {
    }

    // need to cast uint8_t to int to print properly
    void print(){
        // C-style casts
        std::cout << "r=" << (int)m_red << " g=" << (int)m_green << " b=" << (int)m_blue << " a=" << (int)m_alpha << "\n"; 

        // Static casts - checks if ptr and pointee types are compatible e.g. int* ptr to char is not okay, use when know object refers to specific type
        std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) << " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << "\n";

        // Dynamic casts - casting from parent class to child class e.g. Animal to Dog, and checks if object is actually castable at runtime (ret null if not)
        // More on casting - https://stackoverflow.com/questions/28002/regular-cast-vs-static-cast-vs-dynamic-cast
    }

};

int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}