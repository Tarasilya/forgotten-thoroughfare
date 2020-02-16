#include "rect_collision_box.h"
#include <algorithm>

const double eps = 1e-09;

RectCollisionBox::RectCollisionBox(double x1, double y1, double x2, double y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {}


bool RectCollisionBox::Collide(CollisionBox* box) {
    return box->Collide(this);
}

bool RectCollisionBox::Collide(RectCollisionBox* box) {
    return x1 + eps < box->x2 && box->x1 + eps < x2 &&
        y1 + eps < box->y2 && box->y1 + eps < y2;
}

void RectCollisionBox::Move(double dx, double dy) {
    x1 += dx;
    x2 += dx;
    y1 += dy;
    y2 += dy;
}

std::pair<double> GetCorrection(CollisionBox* box, double dx, double dy) {
	box->Move(dx, dy);
	double too_low = max(box->y2 - y1, 0);
	double too_high = max(y2 - box->y1, 0);
	double too_right = max()
	box->Move(-dx, -dy);
	return 
}