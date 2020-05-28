#pragma once

#include "component.h"

#include <string>

#include <SFML/Graphics.hpp>

namespace component {

class Rectangle: public Component{

private:
    std::pair<double, double> size_;
    sf::Color color_;
    int layer_;
    double thickness_;
    sf::Color outline_color_;

public:
    Rectangle(double width, 
        double height,
        sf::Color color,
        int layer = 0,
        double thickness = 0,
        sf::Color outline_color = sf::Color(0, 0, 0, 0));
    
    sf::Color GetColor();
    sf::Color GetOutlineColor();
    std::pair<double, double> GetSize();
    double GetThickness();
    int GetLayer();
    void SetWidth(double width);
};

}
