#include "position.h"

Position::Position() {}
Position::Position(double x, double y):x_(x), y_(y) {}
double Position::GetX() const {
    return x_;
}
double Position::GetY() const {
    return y_;
}