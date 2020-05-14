#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class CraftItem: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    CraftItem(SystemManager* manager);

    void Tick(double dt) override;
};

}
