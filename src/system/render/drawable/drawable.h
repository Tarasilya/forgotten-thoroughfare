#pragma once

#include <SFML/Graphics.hpp>

class Drawable {
public:
    virtual void Draw(sf::RenderWindow* window) = 0;
    virtual void Move(double dx, double dy) = 0;
    bool HUD = false;
};