#include "collision.h"

#include "entity.h"


namespace component {

Collision::Collision(Entity* entity) {
    AddEntity(entity);
}

void Collision::AddEntity(Entity* entity) {
    entities_.push_back(entity);
}

const std::vector<Entity*> Collision::GetEntities() {
    return entities_;
}

}

