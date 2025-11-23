#pragma once
#include <iostream>
#include <string>

class Ball{

public:
    std::string m_color{"black"}; // Non-static member initialisation
    float m_radius{10.0};

public:
    Ball() = default;

    Ball(std::string_view m_color, float m_radius): m_color{m_color}, m_radius{m_radius}{
    }

    Ball(std::string_view m_color) : Ball(m_color, 0){}

    Ball(float radius) : Ball("red", 1){
    }

    void print(){
        std::cout << "color: " << m_color << ", radius: " << m_radius << "\n";
    }
};
