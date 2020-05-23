#pragma once

#include "system/system.h"


namespace systems {

class Renderer: public System {
protected:
    void InitUsedState() override;

public:
    Renderer(SystemManager* manager);

    void Tick(double dt) override;
};

}
