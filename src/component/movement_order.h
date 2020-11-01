#pragma once

#include "component.h"

#include <deque>

class Entity;

namespace component {

class MovementOrder: public Component {
private:
    std::deque<Entity*> path_;

public:
    MovementOrder(std::deque<Entity*> path);
    const std::deque<Entity*>& Path();
    void PopFirst();
    int Size();
};

}
