#pragma once

#include "system.h"

#include <SFML/Graphics.hpp>


namespace systems {

class SystemManager;

class Rendering: public System {
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    Rendering(SystemManager* manager);

    void Tick(double dt) override;
};

}
