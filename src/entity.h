#pragma once

#include "type.h"

#include <iostream>
#include <map>
#include <string>

class Component;

class Entity {
private:
    std::map<std::string, Component*> components_;

public:
    Entity();

    template<class T>
    void AddComponent(T* component) {
        std::string typ = type(*component);
        std::cerr << "Entity::AddComponent 1type: " << typ << std::endl;
        components_[typ] = component;
    }
    bool HasComponent(const std::string& component);

    template<class T>
    T* GetComponent() {
        assert(components_.find(type<T>()) != components_.end());

        return dynamic_cast<T*>(components_[type<T>()]);
    }    
};