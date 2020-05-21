#pragma once

#include "component/mouse.h"

#include "system/system.h"


namespace systems {

class SystemManager;

class MouseInput: public System {
private:
    static const Aspect mouse_aspect_;
protected:
    void InitUsedState() override;

public:
    MouseInput(SystemManager* manager);

    void Tick(double dt) override;
};

}
