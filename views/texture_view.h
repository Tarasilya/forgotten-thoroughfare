#pragma once

#include "view.h"
#include "always_visible.h"

#include <SFML/Graphics.hpp>

#include <map>

class Visible;
class Position;

class TextureView : public View {
private:
    static std::map<std::string, sf::Texture*> textures_;

    sf::Sprite* sprite_;
    sf::Texture* texture_;

    Visible* visibility_ = new AlwaysVisible();
    Position* position_;
    Painter* painter_;

    void ScaleToSize(double width, double height);
public:
    TextureView(const std::string& file, Position* position);
    TextureView* SetSize(double width, double height);
    TextureView* SetZ(int z);
    TextureView* SetVisibility(Visible* visibility);

    void Draw(Painter* painter);
    void Draw(Painter* painter, double x, double y);
};