#pragma once

#include "system.h"


namespace systems {

class SystemManager;

class CollisionDetection: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    CollisionDetection(SystemManager* manager);

    void Tick(double dt) override;
};

}
