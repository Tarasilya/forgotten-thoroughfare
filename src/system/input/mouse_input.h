#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class MouseInput: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    MouseInput(SystemManager* manager);

    void Tick(double dt) override;
};

}
