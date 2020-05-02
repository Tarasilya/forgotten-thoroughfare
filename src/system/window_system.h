#pragma once

#include "system.h"

#include <SFML/Graphics.hpp>

class SystemManager;

class WindowSystem: public System {
public:
    WindowSystem(SystemManager* manager);

    void Tick(double dt) override;
};
