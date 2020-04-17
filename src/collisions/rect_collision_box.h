#pragma once

#include "collision_box.h"
#include "null_collision_box.h"


#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <utility>

class RectCollisionBox : public CollisionBox {    
public:
    double x1;
    double y1;
    double x2;
    double y2;

    RectCollisionBox(double x1, double y1, double x2, double y2);
    bool Collide(CollisionBox* box) override;
    bool Collide(RectCollisionBox* box) override;
    bool Collide(NullCollisionBox* box) override;

    void Move(double dx, double dy) override;

    std::pair<double, double> GetCorrection(RectCollisionBox* box, double dx, double dy);
};