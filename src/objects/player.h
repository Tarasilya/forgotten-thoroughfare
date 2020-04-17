#pragma once

#include "objects/game_object.h"
#include "objects/damageable.h"
#include "views/position.h"
#include "backpack/backpack.h"

#include <unordered_map>
#include <string>
#include <vector>


const std::string UP = "up";
const std::string DOWN = "down";
const std::string LEFT = "left";
const std::string RIGHT = "right";
const std::string BACKPACK = "backpack";
const std::string DROP = "drop";
const std::string PICKUP = "pickup";
const std::string TAUNT = "taunt";
const std::string ATTACK = "attack";
const std::string CRAFT_NOW = "craft_now";
const std::string MENU_INTERACTION = "menu_interaction"; 
const std::string CRAFT = "craft";

const std::vector<std::string> PLAYER_ACTIONS = 
    {UP, DOWN, LEFT, RIGHT, BACKPACK, DROP, PICKUP, TAUNT, ATTACK, CRAFT_NOW, MENU_INTERACTION, CRAFT};

const double PLAYER_SIZE = 0.1;

class Attack;
class Game;
class PlayerView;
class RectCollisionBox;
class HpBar;
class Taunt;
class CraftView;
class View;

enum InfoStatus{NO_MENU, BACKPACK_MENU, CRAFT_MENU};

class Player : public GameObject, public Damageable, public Position {
private:
    double x_;
    double y_;
    double horizontal_speed_;
    double vertical_speed_;

    View* view_;
    HpBar* hp_bar_;
    Taunt* taunt_;
    Attack* attack_;
    InfoStatus info_status_;
    CraftView* craft_view_;

    bool backpack_visibility_;
    Game* game_;
    RectCollisionBox* collision_box_;
    Backpack* backpack_;

    void Move(double dx, double dy);

    int direction_ = 1;
    bool authority_;

    void InitBackpack();

public:
    Player(double x, double y, Game* game, bool authority);
    CollisionBox* GetCollisionBox() const override;
    void Tick(double dt) override;
    bool Collidable(Player* p) override;
    bool Pickupable(Player* p) override;

    void SetCraftView(CraftView* craft_view);
    bool Damage(double dmg) override;
    
    int GetDirection() const;

    double GetX() const override;
    double GetY() const override;
    Backpack* GetBackpack();
    Taunt* GetTaunt();
    InfoStatus GetInfoStatus();

    void ActionUp();
    void ActionDown();
    void ActionLeft();
    void ActionRight();
    void ActionBackpack();
    void ActionDrop();
    void ActionPickup();
    void ActionTaunt();
    void ActionAttack();
    void ActionCraftNow();
    void ActionMenuInteraction();
    void ActionCraft();
};
