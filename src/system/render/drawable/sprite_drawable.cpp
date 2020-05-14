#include "sprite_drawable.h"

#include <iostream>

SpriteDrawable::SpriteDrawable(sf::Sprite* sprite): sprite_(sprite) {}

void SpriteDrawable::Draw(sf::RenderWindow* window) {
    window->draw(*sprite_);
}

void SpriteDrawable::Move(double dx, double dy) {
    sprite_->move(dx, dy);
}
