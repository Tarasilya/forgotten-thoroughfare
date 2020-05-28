#pragma once

#include "component.h"

#include <SFML/Graphics.hpp>

namespace systems {
class SystemManager;
}
class Entity;

namespace component {

class Hp: public Component {
private:
    int hp_;
    int max_;

    Entity* green_rect_;
    Entity* red_rect_;

    static Entity* CreateHpRect(std::string name, 
        sf::Color color,
        Entity* entity);
    void UpdateRects();

public:
    Hp(int max, Entity* entity, systems::SystemManager* system_manager_);

    void Change(int delta);
    int Get();
};

}
