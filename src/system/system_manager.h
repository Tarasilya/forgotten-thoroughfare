#pragma once

#include "entity.h"

#include <vector>


namespace systems {

class System;

class SystemManager {
private:
    std::vector<System*> systems_;

    Entity* state_;

public:
    SystemManager();

    void AddSystem(System* system);

    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);

    template<class T>
    void ComponentRemoved(Entity* entity);

    template<class T>
    void ComponentAdded(Entity* entity);

    template<class T>
    void AddComponentToState(T* component);

    template<class T>
    T* GetComponentFromState();

    void Tick(double dt);
};

}

#include "system.h"


namespace systems {

template <class T>
void SystemManager::ComponentRemoved(Entity* entity) {
    for (auto system: systems_) {
        system->ComponentRemoved<T>(entity);
    }
}

template <class T>
void SystemManager::ComponentAdded(Entity* entity) {
    for (auto system: systems_) {
        system->ComponentAdded<T>(entity);
    }
}

template<class T>
void SystemManager::AddComponentToState(T* component) {
    state_->AddComponent(component);
}

template<class T>
T* SystemManager::GetComponentFromState() {
    return state_->GetComponent<T>();
}

}
