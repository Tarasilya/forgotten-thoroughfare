#include "painter.h"
#include "rat.h"
#include "rat_view.h"

#include <iostream>

RatView::RatView(Rat* rat) : rat_(rat) {
    sf::Texture* texture_ = new sf::Texture();
    if (!texture_->loadFromFile("mouse_assassin-min.jpg")){
        std::cerr << "Could not load image";
    }
    sprite_.setTexture(*texture_);
    sprite_.scale(sf::Vector2f(0.5f, 0.5f));
}
void RatView::Draw(Painter* painter) {
    sprite_.setPosition(painter->Transform(rat_->GetX(), painter->Width()), painter->Transform(rat_->GetY(), painter->Height()));
    painter->Draw(sprite_);
}
