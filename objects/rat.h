#pragma once

#include "game_object.h"
#include "views/rat_view.h"

#include <unordered_map>
#include <string>


const std::string UP = "up";
const std::string DOWN = "down";
const std::string LEFT = "left";
const std::string RIGHT = "right";


class Game;
class RectCollisionBox;

class Rat : public GameObject {
private:
    int i_;
    double x_;
    double y_;
    Game* game_;
    RectCollisionBox* collision_box_;
    std::unordered_map<std::string, sf::Keyboard::Key> moves;


    void Move(double dx, double dy);

public:
    Rat(double x, double y, double i, Game* game);
    CollisionBox* GetCollisionBox() override;
    void Tick(double dt) override;
    bool ProcessKey(sf::Keyboard::Key key, bool pressed) override;

    RatView* view;
    
    double GetX();
    double GetY();
};