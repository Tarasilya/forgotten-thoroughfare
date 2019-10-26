#pragma once

#include "game_object.h"

class Rat : public GameObject {
private:
    int i_;
    double x_;
    double y_;
public:
    Rat(double x, double y, double i);
    CollisionBox* GetCollisionBox() override;
    void Tick(double dt) override;
    bool ProcessKey(sf::Keyboard::Key key) override;
};