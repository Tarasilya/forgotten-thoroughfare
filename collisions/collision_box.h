#pragma once

#include <cstdio>


class RectCollisionBox;
class NullCollisionBox;

class CollisionBox {
public:
    virtual bool Collide(CollisionBox* box) = 0; 
    virtual bool Collide(RectCollisionBox* box) = 0;
    virtual bool Collide(NullCollisionBox* box) = 0;
    virtual void Move(double dx, double dy) = 0;
};