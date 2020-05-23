#pragma once

#include "system/system.h"


namespace systems {

class CameraApply: public System {
protected:
    void InitUsedState() override;

public:
    CameraApply(SystemManager* manager);

    void Tick(double dt) override;
};

}
