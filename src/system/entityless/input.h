#pragma once

#include "entityless.h"


namespace systems {

class SystemManager;

class Input: public Entityless {
protected:
    void InitUsedState() override;

public:
    Input(SystemManager* manager);

    void Tick(double dt) override;
};

}
