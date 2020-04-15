#pragma once

class Position {
private:
    double x_;
    double y_;
public:
    Position();
    Position(double x, double y);
    virtual double GetX() const;
    virtual double GetY() const;
};