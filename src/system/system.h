#pragma once

#include <set>
#include <string>


class Entity;

namespace systems {

class SystemManager;

class System {
private:
    std::set<std::string> required_components_;
    std::set<std::string> used_state_;
    std::string name_;
    std::set<Entity*> entities_;

protected:
    SystemManager* system_manager_;

    virtual void InitRequiredComponents() = 0;
    virtual void InitUsedState() = 0;

    virtual const std::set<Entity*>& Entities();

    template<class T>
    void AddRequiredComponent();

    template<class T>
    void AddUsedState();

public:
    System(SystemManager* manager, const std::string& name);

    void PrintComponents();

    virtual void Tick(double dt) = 0;
    std::string Name();

    template<class T> 
    T* GetComponent(Entity* entity);

    template<class T>
    T* GetState();

    template<class T>
    void ComponentRemoved(Entity* entity);

    template<class T>
    void ComponentAdded(Entity* entity);
};

}

#include "system_manager.h"
#include "type.h"


namespace systems {
 
template<class T>
void System::AddRequiredComponent() {
    required_components_.insert(type<T>());
}

template<class T>
void System::AddUsedState() {
    used_state_.insert(type<T>());
}

template<class T> 
T* System::GetComponent(Entity* entity) {
    assert(required_components_.find(type<T>()) != required_components_.end()
        && "Tried to use component that's not registered");
    return entity->GetComponent<T>();
}

template<class T>
T* System::GetState() {
    assert(used_state_.find(type<T>()) != used_state_.end()
        && "Tried to use state that's not registered");
    return system_manager_->GetComponentFromState<T>();
}

template<class T>
void System::ComponentRemoved(Entity* entity) {
    if (required_components_.find(type<T>()) != required_components_.end()) {
        entities_.erase(entity);
    }
}

template<class T>
void System::ComponentAdded(Entity* entity) {
    if (required_components_.find(type<T>()) != required_components_.end()
            && entities_.find(entity) == entities_.end()) {
        TryAddEntity(entity);
    }
}

}
