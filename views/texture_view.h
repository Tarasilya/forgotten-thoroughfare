#pragma once

#include "view.h"

#include <SFML/Graphics.hpp>

#include <map>

class TextureView : public View {
private:
    static std::map<std::string, sf::Texture*> textures_;

    sf::Sprite* sprite_;
    sf::Texture* texture_;
public:
    TextureView(const std::string& file);
    void SetSize(double width, double height);
    void Draw(Painter* painter, double x, double y);
};