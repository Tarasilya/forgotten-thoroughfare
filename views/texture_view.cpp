#include "texture_view.h"

#include "painter/painter.h"

#include <cstdio>

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
    printf("%.2f %.2f\n", width / size.x, height / size.y);
    sprite_->scale(sf::Vector2f(width / size.x, height / size.y));
}
void TextureView::Draw(Painter* painter, double x, double y) {
    sprite_->setPosition(
        painter->Transform(x, painter->Width()),
        painter->Transform(y, painter->Height()));
    painter->Draw(sprite_);
}