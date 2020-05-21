#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class RectanglePreRender: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    RectanglePreRender(SystemManager* manager);

    void Tick(double dt) override;
};

}
