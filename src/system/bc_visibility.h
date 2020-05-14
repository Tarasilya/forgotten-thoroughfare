#pragma once

#include "system/system.h"

#include <string>


class Entity;

namespace systems {

class SystemManager;

class BCVisibility: public System {
private:
    Entity* CreateTextEntity(Entity* parent, std::string content);
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    BCVisibility(SystemManager* manager);

    void Tick(double dt) override;
};

}
