#pragma once

#include "drawable.h"

class SpriteDrawable: public Drawable {
private:
    sf::Sprite* sprite_;
public:
    SpriteDrawable(sf::Sprite* sprite);
    void Draw(sf::RenderWindow* window) override;
    void Move(double dx, double dy) override;
};