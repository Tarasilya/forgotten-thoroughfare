#pragma once

#include "system/entityless.h"

#include <SFML/Graphics.hpp>


namespace systems {

class PlayerCommands: public Entityless {
private:
    std::map<std::string, sf::Keyboard::Key> controls_;
protected:
    void InitUsedState() override;

public:
    PlayerCommands(SystemManager* manager);

    void Tick(double dt) override;
};

}
