#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class CameraMovement: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    CameraMovement(SystemManager* manager);

    void Tick(double dt) override;
};

}
