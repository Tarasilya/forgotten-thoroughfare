#pragma once

class CollisionBox {
    virtual bool collide(RectCollisionBox* box) = 0;
};