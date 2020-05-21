#pragma once

#include "drawable.h"

class RectangleDrawable: public Drawable {
private:
    sf::RectangleShape* rectangle_;
public:
    RectangleDrawable(sf::RectangleShape* sprite);
    void Draw(sf::RenderWindow* window) override;
    void Move(double dx, double dy) override;
};