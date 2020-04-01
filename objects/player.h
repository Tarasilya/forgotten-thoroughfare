#pragma once

#include "objects/game_object.h"
#include "views/player_view.h"
#include "backpack/backpack.h"
#include "objects/taunt/taunt.h"

#include <unordered_map>
#include <string>


const std::string UP = "up";
const std::string DOWN = "down";
const std::string LEFT = "left";
const std::string RIGHT = "right";
const std::string BACKPACK = "backpack";
const std::string DROP = "drop";
const std::string PICKUP = "pickup";
const std::string DAMAGE = "damage";
const std::string HEAL = "heal";
const std::string TAUNT = "taunt";


class Game;
class RectCollisionBox;
class HpBar;

class Player : public GameObject {
private:
    double x_;
    double y_;
    double horizontal_speed_;
    double vertical_speed_;

    HpBar* hp_bar_;
    Taunt* taunt_;

    bool backpack_visibility_;
    Game* game_;
    RectCollisionBox* collision_box_;
    std::unordered_map<std::string, sf::Keyboard::Key> moves;
    Backpack* backpack_;

    void Move(double dx, double dy);
    void MoveTaunt(double dx, double dy);
    void PickUpItems();

public:
    Player(double x, double y, Game* game);
    CollisionBox* GetCollisionBox() const override;
    void Tick(double dt) override;
    bool ProcessKey(sf::Keyboard::Key key, bool pressed, bool repeated) override;
    bool Collidable(Player* p) override;
    bool Pickupable(Player* p) override;

    PlayerView* view;
    
    double GetX() const;
    double GetY() const;
    Backpack* GetBackpack();
    Taunt* GetTaunt();
    bool GetBackpackVisibility();
    void FundamentallyExerciseTaunt();
};
