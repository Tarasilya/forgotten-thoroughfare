#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class MovementApply: public System {
private:
    static const Aspect movement_aspect_;
protected:
    void InitUsedState() override;

public:
    MovementApply(SystemManager* manager);

    void Tick(double dt) override;
};

}
