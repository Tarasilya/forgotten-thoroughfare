#include "text_drawable.h"


TextDrawable::TextDrawable(sf::Text* text): text_(text) {}

void TextDrawable::Draw(sf::RenderWindow* window) {
    window->draw(*text_);
}

void TextDrawable::Move(double dx, double dy) {
    text_->move(dx, dy);
}
