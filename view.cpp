#include "view.h"
#include "painter.h"

View::View(double x, double y) : x_(x), y_(y) {}

void View::Move(double dx, double dy) {
    x_ += dx;
    y_ += dy;
}

void View::Draw(Painter* painter) {
    painter->Draw({x_ - size, y_ - size, x_ + size, y_ + size, Color(50, 150, 75)});
}