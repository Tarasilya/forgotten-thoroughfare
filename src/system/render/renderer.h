#pragma once

#include "system/entityless.h"


namespace systems {

class Renderer: public Entityless {
protected:
    void InitUsedState() override;

public:
    Renderer(SystemManager* manager);

    void Tick(double dt) override;
};

}
