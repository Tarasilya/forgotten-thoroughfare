#include "system.h"

#include "entity.h"
#include "type.h"

#include <string>
#include <vector>


namespace systems {

System::System(SystemManager* manager, const std::string& name)
        : name_(name), system_manager_(manager) {}

void System::TryAddEntity(Entity* entity) {
    if (entities_.find(entity) != entities_.end()) {
        return;
    }

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

void System::PrintComponents() {
    std::cerr << "(" << name_ << ") required components: ";
    for (auto component: required_components_) {
        std::cerr << "{" << component << "}, ";
    }
    std::cerr << std::endl;

    std::cerr << "(" << name_ << ") used state: ";
    for (auto component: used_state_) {
        std::cerr << "{" << component << "}, ";
    }
    std::cerr << std::endl;
}

const std::set<Entity*>& System::Entities() {
    return entities_;
}

std::string System::Name() {
    return name_;
}

}
