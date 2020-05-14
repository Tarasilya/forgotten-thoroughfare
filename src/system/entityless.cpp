#include "entityless.h"

namespace systems {

Entityless::Entityless(SystemManager* manager, const std::string& name)
        : System(manager, name) {}

const std::set<Entity*>& Entityless::Entities() {
    assert(false && "Trying to get entities in entityless system");
    return System::Entities();
}

void Entityless::InitRequiredComponents() {}

void Entityless::TryAddEntity(Entity* entity) {}

}
