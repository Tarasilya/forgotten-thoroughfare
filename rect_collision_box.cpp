#include "rect_collision_box.h"

const double eps = 1e-09;

RectCollisionBox::RectCollisionBox(double x1, double y1, double x2, double y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {}


bool RectCollisionBox::collide(RectCollisionBox* box) {
    return x1 + eps < box.x2 && box.x1 + eps < x2 &&
        y1 + eps < box.y2 && box.y1 + eps < y2;
}