#pragma once

#include "collision_box.h"

class RectCollisionBox : public CollisionBox {
public:
    RectCollisionBox(double x1, double y1, double x2, double y2);
    bool collide(RectCollisionBox* box) override;
};