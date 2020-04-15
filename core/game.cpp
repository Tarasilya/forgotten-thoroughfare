#include "collisions/collision_box.h"
#include "game.h"
#include "map/map.h"
#include "objects/player.h"
#include "objects/items/stick/stick.h"
#include "objects/displayable_object.h"
#include "objects/items/apple/apple.h"
#include "painter/painter.h"
#include "views/view.h"
#include "views/backpack_view.h"
#include "views/craft_view.h"
#include "views/fps_view.h"
#include "backpack/craft.h"



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
}

Game* Game::GetGame() {
    return current_game_;
}

void Game::InitMap() {
    new Map("maps/dumb.map");
}

void Game::AddObject(GameObject* object) {
    objects_.push_back(object);
}

void Game::InitObjects() {
    auto painter = Painter::GetPainter();

    new FpsView();
    Craft::Initialize();

    Player* player = new Player(0.25, 0.5, this);

    for (int i = 0; i < 100; i++) {
        Stick* stick = new Stick(); 
        Apple* apple = new Apple();



        player->GetBackpack()->AddItem(stick);
        player->GetBackpack()->AddItem(apple);
    }

    BackpackView* backpack_view = new BackpackView(player->GetBackpack(), player);
    CraftView* craft_view = new CraftView(player->GetBackpack(), player);
    player->SetCraftView(craft_view);

    std::cerr <<"a" <<std::endl;
    GameObject* punching_bag = (new DisplayableObject(
        "pics/punch_bag.png", false, new RectCollisionBox(0, 0, HP_WIDTH, HP_HEIGHT)))->WithHp(HP_MAX_HP);
    std::cerr <<"b" <<std::endl;
}


void Game::ProcessKey(sf::Keyboard::Key key, bool pressed, bool repeated)
{
    for (auto object : objects_) {
        if (object->ProcessKey(key, pressed, repeated)) {
            break;
        }
    }
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
