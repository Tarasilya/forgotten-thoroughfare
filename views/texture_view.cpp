#include "texture_view.h"

#include "painter/painter.h"
#include "position.h"

#include <cstdio>
#include <iostream>
#include <stdlib.h>

std::map<std::string, sf::Texture*> TextureView::textures_;

TextureView::TextureView(const std::string& file, Position* position) {
    position_ = position;
    sprite_ = new sf::Sprite();

    if (textures_.count(file) == 0) {
        sf::Texture* texture = new sf::Texture();
        if (!texture->loadFromFile(file)){
            printf("Could not load image");
        }        
        textures_[file] = texture;
    }

    texture_ = textures_[file];
    sprite_->setTexture(*texture_);

    painter_ = Painter::GetPainter();
}

TextureView* TextureView::SetSize(double width, double height) {
    ScaleToSize(
            painter_->Transform(width, painter_->Width()), 
            painter_->Transform(height, painter_->Height()));

    return this;
}

TextureView* TextureView::SetVisibility(Visible* visibility) {
    visibility_ = visibility;
    return this;
}

void TextureView::ScaleToSize(double width, double height) {
    auto size = texture_->getSize();
    sprite_->scale(sf::Vector2f(width / size.x, height / size.y));
}

TextureView* TextureView::SetCollisionVisibility(bool collision_visibility) {
    collision_visibility_ = collision_visibility;
}

void TextureView::Rotate(double angle) {
    sprite_->rotate(angle);
}

void TextureView::Draw(Painter* painter) {
    Draw(painter, position_->GetX(), position_->GetY());
}

void TextureView::Draw(Painter* painter, double x, double y) {
    if (visibility_->GetVisibility()) {
        int x1 = painter->Transform(x, painter->Width());
        int y1 = painter->Transform(y, painter->Width());
        sprite_->setPosition(
            x1,
            y1);


        painter->Draw(sprite_);

        if (collision_visibility_) {
            auto rect = sprite_->getGlobalBounds();
            painter->Draw({rect.left, rect.top, rect.left + rect.width, rect.top+rect.height, Color(255, 0, 0)}, false);
        }
    }
}