#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class Select: public System {
private:
    static const Aspect mouse_aspect_;
protected:
    void InitUsedState() override;

public:
    Select(SystemManager* manager);

    void Tick(double dt) override;
};

}
