#pragma once

#include "system.h"


namespace systems {

class SystemManager;

class PlayerMovement: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    PlayerMovement(SystemManager* manager);

    void Tick(double dt) override;
};

}
