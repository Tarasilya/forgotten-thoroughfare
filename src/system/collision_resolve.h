#pragma once

#include "system.h"


namespace systems {

class SystemManager;

class CollisionResolve: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    CollisionResolve(SystemManager* manager);

    void Tick(double dt) override;
};

}
