#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class CraftSelect: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    CraftSelect(SystemManager* manager);

    void Tick(double dt) override;
};

}
