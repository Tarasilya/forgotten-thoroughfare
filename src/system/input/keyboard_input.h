#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class KeyboardInput: public System {
protected:
    void InitUsedState() override;

public:
    KeyboardInput(SystemManager* manager);

    void Tick(double dt) override;
};

}
