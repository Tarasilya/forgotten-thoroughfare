#pragma once

#include "component.h"

#include <vector>

class Entity;

namespace component {

class Collision: public Component {
private:
    std::vector<Entity*> entities_;
public:
    Collision(Entity* entity);

    void AddEntity(Entity* entity);
    const std::vector<Entity*> GetEntities();
};

}
