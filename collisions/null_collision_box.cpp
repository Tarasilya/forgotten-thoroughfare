#include "rect_collision_box.h"

bool NullCollisionBox::Collide(CollisionBox* box) {
    return box->Collide(this);
}

bool NullCollisionBox::Collide(NullCollisionBox* box) {
    return false;
}

bool NullCollisionBox::Collide(RectCollisionBox* box) {
    return false;
}

void NullCollisionBox::Move(double dx, double dy) {}