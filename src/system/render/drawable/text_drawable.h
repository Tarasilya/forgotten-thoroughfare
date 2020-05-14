#pragma once

#include "drawable.h"

class TextDrawable: public Drawable {
private:
    sf::Text* text_;
public:
    TextDrawable(sf::Text* text);
    void Draw(sf::RenderWindow* window) override;
    void Move(double dx, double dy) override;
};