#pragma once

#include "system/entityless.h"


namespace systems {

class CameraApply: public Entityless {
protected:
    void InitUsedState() override;

public:
    CameraApply(SystemManager* manager);

    void Tick(double dt) override;
};

}
