#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class MovementApply: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    MovementApply(SystemManager* manager);

    void Tick(double dt) override;
};

}
