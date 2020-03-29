#pragma once

#include "objects/game_object.h"
#include "views/player_view.h"
#include "backpack/backpack.h"

#include <unordered_map>
#include <string>


const std::string UP = "up";
const std::string DOWN = "down";
const std::string LEFT = "left";
const std::string RIGHT = "right";
const std::string BACKPACK = "backpack";
const std::string DROP = "drop";


class Game;
class RectCollisionBox;

class Player : public GameObject {
private:
    double x_;
    double y_;
    double horizontal_speed_;
    double vertical_speed_;

    bool backpack_visibility_;
    Game* game_;
    RectCollisionBox* collision_box_;
    std::unordered_map<std::string, sf::Keyboard::Key> moves;
    Backpack* backpack_;

    void Move(double dx, double dy);

public:
    Player(double x, double y, Game* game);
    CollisionBox* GetCollisionBox() override;
    void Tick(double dt) override;
    bool ProcessKey(sf::Keyboard::Key key, bool pressed, bool repeated) override;

    PlayerView* view;
    
    double GetX();
    double GetY();
    Backpack* GetBackpack();
    bool GetBackpackVisibility();
};