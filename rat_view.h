#pragma once

#include "view.h"

#include <SFML/Graphics.hpp>

class Rat;

class RatView : public View{
private:
    Rat* rat_;
    sf::Sprite sprite_;
public:
    RatView(Rat* rat);
    void Draw(Painter* painter) override;
};