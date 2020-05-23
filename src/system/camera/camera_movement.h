#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class CameraMovement: public System {
private:
    static const Aspect mouse_aspect_;
protected:
    void InitUsedState() override;

public:
    CameraMovement(SystemManager* manager);

    void Tick(double dt) override;
};

}
