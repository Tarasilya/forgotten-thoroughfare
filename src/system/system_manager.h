#pragma once

#include "entity.h"
#include "performance_data.h"

#include <chrono>
#include <vector>


namespace systems {

class System;

class SystemManager {
private:
    std::vector<System*> systems_;
    std::vector<PerformanceData<std::chrono::microseconds>> performance_;

    int time_ = 0;

    Entity* state_;

    std::chrono::microseconds MeasureTick(System* system, int dt);

public:
    SystemManager();

    void AddSystem(System* system);

    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);

    template<class T>
    void AddComponent(Entity* entity, T* value);

    template<class T>
    void RemoveComponent(Entity* entity);

    template<class T>
    void AddComponentToState(T* component);

    template<class T>
    T* GetComponentFromState();

    void Tick(int dt);
};

}

#include "system.h"


namespace systems {

template <class T>
void SystemManager::RemoveComponent(Entity* entity) {
    entity->RemoveComponent<T>();
    for (auto system: systems_) {
        system->ComponentRemoved<T>(entity);
    }
}

template <class T>
void SystemManager::AddComponent(Entity* entity, T* value) {
    entity->AddComponent(value);
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
