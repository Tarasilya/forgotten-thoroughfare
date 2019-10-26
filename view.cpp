#include "view.h"
#include "painter.h"
#include "iostream"

View::View(double x, double y) {
  x_ = x;
  y_ = y;
  if (!player_texture.loadFromFile("mouse_assassin-min.jpg")){
    std::cerr << "Could not load image";
  }
  player_sprite.setTexture(player_texture);
  player_sprite.scale(sf::Vector2f(0.5f, 0.5f));
}

void View::Move(double dx, double dy) {
    x_ += dx;
    y_ += dy;
}

void View::Draw(Painter* painter) {
  // painter->Draw({x_ - size, y_ - size, x_ + size, y_ + size, Color(50, 150, 75)});
  player_sprite.setPosition(x_, y_);
  painter->Draw(player_sprite);
}
