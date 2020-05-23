#include "rectangle_drawable.h"

#include <iostream>

RectangleDrawable::RectangleDrawable(sf::RectangleShape* rectangle): rectangle_(rectangle) {}

void RectangleDrawable::Draw(sf::RenderWindow* window) {
    window->draw(*rectangle_);
}

void RectangleDrawable::Move(double dx, double dy) {
    rectangle_->move(dx, dy);
}
