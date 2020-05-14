#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class SpritePreRender: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    SpritePreRender(SystemManager* manager);

    void Tick(double dt) override;
};

}
