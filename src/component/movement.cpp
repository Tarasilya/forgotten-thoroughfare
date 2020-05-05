#include "movement.h"


namespace component {

Movement::Movement(double dx, double dy)
        : dx_(dx), dy_(dy) {}

double Movement::GetDx() {
    return dx_;
}

double Movement::GetDy() {
    return dy_;
}

void Movement::Set(double dx, double dy) {
    dx_ = dx;
    dy_ = dy;
}

void Movement::SetDx(double dx) {
    dx_ = dx;
}

void Movement::SetDy(double dy) {
    dy_ = dy;
}

}
