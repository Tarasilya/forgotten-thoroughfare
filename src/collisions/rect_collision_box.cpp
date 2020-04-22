#include "rect_collision_box.h"
#include "null_collision_box.h"


const double eps = 1e-09;

RectCollisionBox::RectCollisionBox(double x1, double y1, double x2, double y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {}


bool RectCollisionBox::Collide(CollisionBox* box) {
    return box->Collide(this);
}

bool RectCollisionBox::Collide(NullCollisionBox* box) {
    return false;
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

std::pair<double, double> RectCollisionBox::GetCorrection(RectCollisionBox* box, double dx, double dy) {

	/**
	returns correction to be applied after move(dx, dy) to avoid colliding boxes
	**/
	
	std::pair<double, double> correction;
	
	double too_low = std::max(box->y2 - y1, 0.0);
	
	if (too_low > y2 + box->y2 - y1 - box->y1) {
		too_low = 0;
	}
	
	double too_high = std::max(y2 - box->y1, 0.0);

	if (too_high > y2 + box->y2 - y1 - box->y1) {
		too_high = 0;
	}

	double too_right = std::max(- box->x1 + x2, 0.0);
	 
	if (too_right > box->x2 + x2 - box->x1 - x1) {
		too_right = 0;
	}

	double too_left = std::max(box->x2 - x1, 0.0);

	if (too_left > box->x2 + x2 - box->x1 - x1) {
		too_left = 0;
	}

	correction.first = abs(too_low + too_high);
	correction.second = abs(too_right + too_left);

	return correction;
}