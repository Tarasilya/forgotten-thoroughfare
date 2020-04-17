#include "game.h"

#include "backpack/craft.h"
#include "collisions/collision_box.h"
#include "core/game/player_action_controller.h"
#include "map/map.h"
#include "objects/player.h"
#include "objects/items/stick/stick.h"
#include "objects/displayable_object.h"
#include "objects/items/apple/apple.h"
#include "views/view.h"
#include "views/backpack_view.h"
#include "views/craft_view.h"
#include "views/fps_view.h"
#include "util/config_reader.h"



#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdio>

const double HP_WIDTH = 0.05;
const double HP_HEIGHT = 0.1;
const double HP_MAX_HP = 100;

Game* Game::current_game_ = 0;

void Game::StartGame() {
    current_game_ = new Game();
    current_game_->InitObjects();
    current_game_->InitMap();
    current_game_->InitPlayer();
}

Game* Game::GetGame() {
    return current_game_;
}

void Game::InitPlayer() {
    player1_ = new Player(0.25, 0.5, this);
    player2_ = new Player(0.25, 0.5, this);
    CraftView* craft_view = new CraftView(player1_->GetBackpack(), player1_);
    player1_->SetCraftView(craft_view);

    InitPlayerControls();
}


void Game::InitPlayerControls() {
    ConfigReader* controls_config = new ConfigReader("controls.txt");
    auto controls = controls_config->GetControls();

    action_controller_ = new PlayerActionController();
    action_controller_->AddAction({UP, controls[UP], true, &Player::ActionUp});
    action_controller_->AddAction({DOWN, controls[DOWN], true, &Player::ActionDown});
    action_controller_->AddAction({LEFT, controls[LEFT], true, &Player::ActionLeft});
    action_controller_->AddAction({RIGHT, controls[RIGHT], true, &Player::ActionRight});
    action_controller_->AddAction({BACKPACK, controls[BACKPACK], false, &Player::ActionBackpack});
    action_controller_->AddAction({DROP, controls[DROP], false, &Player::ActionDrop});
    action_controller_->AddAction({PICKUP, controls[PICKUP], true, &Player::ActionPickup});
    action_controller_->AddAction({TAUNT, controls[TAUNT], false, &Player::ActionTaunt});
    action_controller_->AddAction({ATTACK, controls[ATTACK], false, &Player::ActionAttack});
    action_controller_->AddAction({CRAFT_NOW, controls[CRAFT_NOW], false, &Player::ActionCraftNow});
    action_controller_->AddAction({MENU_INTERACTION, controls[MENU_INTERACTION], false, &Player::ActionMenuInteraction});
    action_controller_->AddAction({CRAFT, controls[CRAFT], false, &Player::ActionCraft});
}

void Game::InitMap() {
    new Map("maps/dumb.map");
}

void Game::AddObject(GameObject* object) {
    objects_.push_back(object);
}

void Game::InitObjects() {
    new FpsView();
    Craft::Initialize();
    GameObject* punching_bag = (new DisplayableObject(
        "pics/punch_bag.png", false, new RectCollisionBox(0, 0, HP_WIDTH, HP_HEIGHT)))->WithHp(HP_MAX_HP);
}


void Game::ProcessAction(const std::string& action) {
    if (action == BACKPACK
            || action == CRAFT
            || action == CRAFT_NOW
            || action == MENU_INTERACTION) {
        return;
    }
    action_controller_->TriggerAction(action, player2_);
}

std::string Game::ProcessKey(sf::Keyboard::Key key, bool pressed, bool repeated)
{
    std::string action = action_controller_->GetActionId(key, pressed, repeated);
    if (action != "") {
        action_controller_->TriggerAction(action, player1_);
    }
    return action;
}

void Game::Tick(double dt)
{
    for (auto object : objects_) {
        object->Tick(dt);
    }
}

std::vector<GameObject*>& Game::GetCollision(CollisionBox* collision_box) {
    std::vector<GameObject*>* collided_objects = new std::vector<GameObject*>();
    for (auto object : objects_) {
        if (object->GetCollisionBox()->Collide(collision_box)) {
            collided_objects->push_back(object);
        }
    }
    return *collided_objects;
}
