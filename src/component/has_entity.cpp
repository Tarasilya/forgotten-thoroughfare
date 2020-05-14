#include "has_entity.h"

#include "entity.h"


void HasEntity::SetEntity(Entity* entity) {
    entity_ = entity;
}

Entity* HasEntity::GetEntity() {
    return entity_;
}

void HasEntity::RemoveEntity() {
    entity_ = 0;
}
