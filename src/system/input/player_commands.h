#pragma once

#include "system/system.h"

#include <SFML/Graphics.hpp>


namespace systems {

class PlayerCommands: public System {
private:
    std::map<std::string, sf::Keyboard::Key> controls_;
protected:
    void InitUsedState() override;

public:
    PlayerCommands(SystemManager* manager);

    void Tick(double dt) override;
};

}
