#pragma once

#include "system/entityless.h"


namespace systems {

class SystemManager;

class KeyboardInput: public Entityless {
protected:
    void InitUsedState() override;

public:
    KeyboardInput(SystemManager* manager);

    void Tick(double dt) override;
};

}
