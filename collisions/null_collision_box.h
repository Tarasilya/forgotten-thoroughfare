#pragma once

#include "collision_box.h"

class NullCollisionBox : public CollisionBox {    
public:
    bool Collide(CollisionBox* box) override;
    bool Collide(RectCollisionBox* box) override;
    bool Collide(NullCollisionBox* box) override;
    void Move(double dx, double dy) override;
};