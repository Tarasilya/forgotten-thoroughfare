#pragma once

#include "system/system.h"

#include <string>


class Entity;
class HasEntity;

namespace systems {

class SystemManager;

class BCVisibility: public System {
private:
    Entity* CreateTextEntity(Entity* parent, std::string content);
    void ToggleEntity(HasEntity* parent, Entity* entity, std::string text);
    void RemoveEntity(HasEntity* parent);
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    BCVisibility(SystemManager* manager);

    void Tick(double dt) override;
};

}
