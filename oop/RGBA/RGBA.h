#pragma once
#include <iostream>
#include <cstdint>

class RGBA{

    using Channel = std::uint8_t;

    const Channel m_red;
    const Channel m_green;
    const Channel m_blue;
    const Channel m_alpha;

public:
    RGBA(Channel m_red = 0, Channel m_green = 0, Channel m_blue = 0, Channel m_alpha = 255) :
        m_red{ m_red }, m_green{ m_green }, m_blue{ m_blue }, m_alpha{ m_alpha }
    {
    }

    void print(){
        std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green)
                  << " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << "\n";
    }

    Channel getRed() const { return m_red; }
    Channel getGreen() const { return m_green; }
    Channel getBlue() const { return m_blue; }
    Channel getAlpha() const { return m_alpha; }
};
