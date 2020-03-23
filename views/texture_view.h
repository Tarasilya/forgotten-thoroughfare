#pragma once

#include "view.h"

#include <SFML/Graphics.hpp>

class TextureView : public View {
private:
    sf::Sprite* sprite_;
    sf::Texture* texture_;
public:
    TextureView(const std::string& file);
    void SetSize(double width, double height);
    void Draw(Painter* painter, double x, double y);
    void PrintBounce();
};