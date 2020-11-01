#pragma once

#include "component.h"


namespace component {

class CollisionRect: public Component {
public:
    double x1;
    double y1;
    double x2;
    double y2;

    CollisionRect(double width, double height);
    CollisionRect(double x1, double y1, double x2, double y2);

    CollisionRect Move(double dx, double dy);

    bool Intersects(const CollisionRect& rect);

    CollisionRect& operator=(const CollisionRect& rect);

    void Print();
};

}
