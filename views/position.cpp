#include "position.h"

Position::Position() {}
Position::Position(double x, double y):x_(x), y_(y) {}
double Position::GetX() {
    return x_;
}
double Position::GetY() {
    return y_;
}