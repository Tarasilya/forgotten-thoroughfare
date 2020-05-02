#pragma once

#include "component.h"

class Transform: public Component {
private:
    double x_;
    double y_;

    double rotation_;

    double scale_x_;
    double scale_y_;

public:
    Transform(double x = 0, double y = 0, 
        double rotation = 0, 
        double scale_x = 1, double scale_y = 1);

    ~Transform() override;

    void SetPosition(double x, double y);
    void SetX(double x);
    void SetY(double y);
    void SetRotation(double rotation);
    void SetScale(double scale_x, double scale_y);

    double GetX();
    double GetY();
    double GetRotation();
    double GetScaleX();
    double GetScaleY();
};
