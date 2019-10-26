#pragma once

#include "painter.h"

const double size = 0.05;

class View {
private:
    double x_;
    double y_;
public:
    View(double x, double y);
    void Move(double dx, double dy);
    void Draw(Painter* painter);
};