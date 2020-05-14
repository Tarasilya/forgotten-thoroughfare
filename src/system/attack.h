#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class Attack: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    Attack(SystemManager* manager);

    void Tick(double dt) override;
};

}
