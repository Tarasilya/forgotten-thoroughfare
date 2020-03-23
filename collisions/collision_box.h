#pragma once

#include <cstdio>
#include <utility>

class RectCollisionBox;

class CollisionBox {
public:
    virtual bool Collide(CollisionBox* box) = 0; 
    virtual bool Collide(RectCollisionBox* box) = 0;

    virtual void Move(double dx, double dy) = 0;

    virtual std::pair<double, double> GetCorrection(RectCollisionBox* box, double dx, double dy) = 0;
};