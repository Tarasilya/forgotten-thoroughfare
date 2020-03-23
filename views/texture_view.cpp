#include "texture_view.h"

#include "painter/painter.h"

#include <cstdio>
#include <iostream>
#include <stdlib.h>

TextureView::TextureView(const std::string& file) {
    sprite_ = new sf::Sprite();
    texture_ = new sf::Texture();
    if (!texture_->loadFromFile(file)){
        printf("Could not load image");
    }
    sprite_->setTexture(*texture_);
}
void TextureView::SetSize(double width, double height) {
    auto size = texture_->getSize();
    printf("setsize: %.2f %.2f %.2f %.2f\n", width, (double) size.x, height, (double) size.y);
    sprite_->scale(sf::Vector2f(width / size.x, height / size.y));
}
void TextureView::Draw(Painter* painter, double x, double y) {
    sprite_->setPosition(
        painter->Transform(x, painter->Width()),
        painter->Transform(y, painter->Height()));

    
    painter->Draw(sprite_);
}

void TextureView::PrintBounce() {
    std::cerr.setf( std::ios::fixed, std:: ios::floatfield );

    auto bounce = sprite_->getGlobalBounds();

    std::cerr << "Sprite: " << bounce.left << " " << bounce.top << " "  << bounce.width << " " << bounce.height << "\n";

}