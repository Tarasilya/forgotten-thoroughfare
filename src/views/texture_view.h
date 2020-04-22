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

    bool collision_visibility_ = false;

    sf::Texture* texture_;

    Visible* visibility_ = new AlwaysVisible();
    Position* position_;
    Painter* painter_;

    void ScaleToSize(double width, double height);

protected:
    sf::Sprite* sprite_;

public:
    TextureView(const std::string& file, Position* position);
    TextureView* SetSize(double width, double height);
    TextureView* SetVisibility(Visible* visibility);
    TextureView* SetCollisionVisibility(bool collision_visibility);

    void Rotate(double angle);

    void Draw(Painter* painter) override;
    void Draw(Painter* painter, double x, double y);
};