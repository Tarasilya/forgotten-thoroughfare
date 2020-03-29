#pragma once

#include <SFML/Graphics.hpp>

class CollisionBox;

class GameObject {
public:
    virtual CollisionBox* GetCollisionBox() = 0;
    virtual void Tick(double dt) = 0;
    virtual bool ProcessKey(sf::Keyboard::Key key, bool pressed, bool repeated) = 0;
};