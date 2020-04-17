#pragma once

#include <SFML/Graphics.hpp>

class CollisionBox;
class Player;

class GameObject {
public:
    GameObject();
    virtual CollisionBox* GetCollisionBox() const = 0;
    virtual void Tick(double dt) = 0;
    virtual bool Collidable(Player* p) = 0;
    virtual bool Pickupable(Player* p);
};