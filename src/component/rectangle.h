#pragma once

#include "component.h"

#include <string>

#include <SFML/Graphics.hpp>

namespace component {

class Rectangle: public Component{

private:
    sf::Color color_;
    std::pair<double, double> size_;
    double thickness_;
    int layer_;

public:
    Rectangle(sf::Color color_, 
        double width_, 
        double height_,
        double thickness_,
        int layer = 0);
    
    sf::Color GetColor();
    std::pair<double, double> GetSize();
    double GetThickness();
    int GetLayer();
};

}
