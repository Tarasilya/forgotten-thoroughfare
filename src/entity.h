#pragma once

#include "type.h"

#include <iostream>
#include <map>
#include <string>

class Component;

class Entity {
private:
    std::map<std::string, Component*> components_;
    std::string name_;

public:
    Entity(std::string name = "");

    const std::string& Name();

    bool HasComponent(const std::string& component);

    template<class T>
    bool HasComponent() {
        std::string typ = type<T>();
        return components_.find(typ) != components_.end();
    }

    template<class T>
    void AddComponent(T* component) {
        assert(components_.find(type<T>()) == components_.end()
            && "Trying to add existing component");
        std::string typ = type<T>();

        //std::cerr << "[" << name_ << "]::AddComponent : {" << typ << "}" << std::endl;
        components_[typ] = component;
    }

    template<class T>
    void RemoveComponent() {
        assert(components_.find(type<T>()) != components_.end()
            && "Trying to remove unexisting component");
        std::string typ = type<T>();

        //std::cerr << "[" << name_ << "]::RemoveComponent : {" << typ << "}" << std::endl;
        components_.erase(typ);
    }

    template<class T>
    T* GetComponent() {
        assert(components_.find(type<T>()) != components_.end()
            && "Trying to get unexisting component");

        return dynamic_cast<T*>(components_[type<T>()]);
    }    
};