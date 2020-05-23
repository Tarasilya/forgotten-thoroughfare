#pragma once

#include <set>
#include <string>


class Entity;

namespace systems {

class SystemManager;

class System {
private:
    std::set<std::string> used_state_;
    std::string name_;
    std::set<Entity*> entities_;

protected:
    SystemManager* system_manager_;

    virtual void InitUsedState() = 0;

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
};

}

#include "system_manager.h"
#include "type.h"


namespace systems {
 
template<class T>
void System::AddUsedState() {
    used_state_.insert(type<T>());
}

template<class T> 
T* System::GetComponent(Entity* entity) {
    return entity->GetComponent<T>();
}

template<class T>
T* System::GetState() {
    assert(used_state_.find(type<T>()) != used_state_.end()
        && "Tried to use state that's not registered");
    return system_manager_->GetComponentFromState<T>();
}


}
