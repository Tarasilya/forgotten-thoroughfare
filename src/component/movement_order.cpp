#include "movement_order.h"

#include <deque>


namespace component {

MovementOrder::MovementOrder(std::deque<Entity*> path): path_(path) {}

const std::deque<Entity*>& MovementOrder::Path() {
    return path_;
}

void MovementOrder::PopFirst() {
    path_.pop_front();
}

int MovementOrder::Size() {
    return path_.size();
}

}
