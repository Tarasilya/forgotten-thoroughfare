#pragma once

class Position {
private:
    double x_;
    double y_;
public:
    Position();
    Position(double x, double y);
    virtual double GetX();
    virtual double GetY();
};