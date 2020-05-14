#include "collision_rect.h"


namespace component {

CollisionRect::CollisionRect(double width, double height)
        : x1(0), y1(0), x2(width), y2(height) {}
CollisionRect::CollisionRect(double x1_, double y1_, double x2_, double y2_)
        : x1(x1_), y1(y1_), x2(x2_), y2(y2_) {}

CollisionRect CollisionRect::Move(double dx, double dy) {
    return CollisionRect(x1 + dx, y1 + dy, x2 + dx, y2 + dy);
}

bool CollisionRect::Intersects(const CollisionRect& rect) {
    return x1 < rect.x2 && y1 < rect.y2 
        && rect.x1 < x2 && rect.y1 < y2;
}

CollisionRect& CollisionRect::operator=(const CollisionRect& rect) {
    x1 = rect.x1;
    x2 = rect.x2;
    y1 = rect.y1;
    y2 = rect.y2;
    return *this;
}

}
