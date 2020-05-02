#pragma once

#include <set>
#include <string>

class Entity;
class SystemManager;

class System {
protected:
    std::set<std::string> required_components_;
    std::set<Entity*> entities_;
    SystemManager* system_manager_;

public:
    System(SystemManager* manager);

    virtual void Tick(double dt) = 0;

    void TryAddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);

    template<class T>
    void ComponentRemovedFromEntity(Entity* entity);
};