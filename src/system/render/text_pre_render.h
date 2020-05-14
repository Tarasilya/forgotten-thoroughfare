#pragma once

#include "system/system.h"

#include <SFML/Graphics.hpp>


namespace systems {

class SystemManager;

class TextPreRender: public System {
private:
    sf::Font font_;
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    TextPreRender(SystemManager* manager);

    void Tick(double dt) override;
};

}
