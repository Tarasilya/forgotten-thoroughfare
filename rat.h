#pragma once

#include "game_object.h"

class Game;
class RectCollisionBox;

class Rat : public GameObject {
private:
    int i_;
    double x_;
    double y_;
    Game* game_;
    RectCollisionBox* collision_box_;

    void Move(double dx, double dy);

public:
    Rat(double x, double y, double i, Game* game);
    CollisionBox* GetCollisionBox() override;
    void Tick(double dt) override;
    bool ProcessKey(sf::Keyboard::Key key) override;

    double GetX();
    double GetY();
};