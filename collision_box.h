#pragma once

#include <cstdio>

class RectCollisionBox;

class CollisionBox {
public:
    bool collide (CollisionBox* box) {
        printf("FUCK\n");
        return false;
    }
    virtual bool collide(RectCollisionBox* box) = 0;
};