#pragma once

#include "system.h"

#include <SFML/Graphics.hpp>

class SystemManager;

class RenderSystem: public System {
private:
    std::map<std::string, sf::Texture*> textures_;
public:
    RenderSystem(SystemManager* manager);

    void Tick(double dt) override;
};
