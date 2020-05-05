#include "entity.h"

#include "component/component.h"

#include <iostream>

Entity::Entity(std::string name) {
    name_ = name;
    components_ = std::map<std::string, Component*>();
}

bool Entity::HasComponent(const std::string& component) {
    return components_.find(component) != components_.end();
}

const std::string& Entity::Name() {
    return name_;
}