#include "view.h"
#include "painter.h"

View::View(double x, double y) : x_(x), y_(y) {}

void View::Move(double dx, double dy) {
    x_ += dx;
    y_ += dy;
}

void View::Draw(Painter* painter) {
  player_sprite.setPosition(painter->Transform(x_, painter->Width()), painter->Transform(y_, painter->Height()));
  painter->Draw(player_sprite);
}
