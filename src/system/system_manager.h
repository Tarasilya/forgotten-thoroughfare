#pragma once

#include "entity.h"
#include "system.h"

#include <vector>

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
    void RemoveComponentFromEntity(Entity* entity) {
        for (auto system: systems_) {
            system->ComponentRemovedFromEntity<T>(entity);
        }
    }

    template<class T>
    void AddComponentToState(T* component) {
        state_->AddComponent(component);
    }

    template<class T>
    T* GetComponentFromState() {
        return state_->GetComponent<T>();
    }

    void Tick(double dt);
};