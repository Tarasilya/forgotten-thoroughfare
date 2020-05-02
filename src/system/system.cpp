#include "system.h"

#include "entity.h"
#include "type.h"

#include <string>
#include <vector>


System::System(SystemManager* manager): system_manager_(manager) {}

void System::TryAddEntity(Entity* entity) {
    for (auto component: required_components_) {
        if (!entity->HasComponent(component)) {
            return;
        }
    }    
    entities_.insert(entity);
}

void System::RemoveEntity(Entity* entity) {
    entities_.erase(entity);
}
