#include "transform.h"


namespace component {

Transform::Transform(double x, double y, 
    double rotation, 
    double scale_x, double scale_y)
        : x_(x), y_(y), rotation_(rotation), scale_x_(scale_x), scale_y_(scale_y)
{}

void Transform::SetPosition(double x, double y) {
    x_ = x;
    y_ = y;
}

void Transform::SetX(double x) {
    x_ = x;
}

void Transform::SetY(double y) {
    y_ = y;
}

void Transform::SetRotation(double rotation) {
    rotation_ = rotation;
}

void Transform::SetScale(double scale_x, double scale_y) {
    scale_x_ = scale_x;
    scale_y_ = scale_y;
}

double Transform::GetX() {
    return x_;
}

double Transform::GetY() {
    return y_;
}

double Transform::GetRotation() {
    return rotation_;
}

double Transform::GetScaleX() {
    return scale_x_;
}

double Transform::GetScaleY() {
    return scale_y_;
}

}
