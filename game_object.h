#pragma once

#include "collision_box.h"

#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual CollisionBox* GetCollisionBox() = 0;
    virtual void Tick(double dt) = 0;
    virtual bool ProcessKey(sf::Keyboard::Key key) = 0;
};