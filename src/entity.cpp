#include "entity.h"

#include "component/component.h"

#include <iostream>

Entity::Entity() {
    components_ = std::map<std::string, Component*>();
}

bool Entity::HasComponent(const std::string& component) {
    std::cerr << "Entity::HasComponent " << component << std::endl;
    return components_.find(component) != components_.end();
}
