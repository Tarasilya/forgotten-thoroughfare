#include "collisions/collision_box.h"
#include "game.h"
#include "map/map.h"
#include "objects/player.h"
#include "objects/items/stick/stick.h"
#include "painter/painter.h"
#include "views/view.h"
#include "views/view_factory.h"
#include "views/backpack_view.h"
#include "views/stick_view.h"


#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdio>

Game* Game::current_game_ = 0;

void Game::StartGame() {
    current_game_ = new Game();
    current_game_->InitMap();
}

Game* Game::GetCurrentGame() {
    return current_game_;
}

Game::Game() {
    InitObjects();
}

void Game::InitMap() {
    new Map("maps/dumb.map");
}

void Game::AddObject(GameObject* object) {
    objects_.push_back(object);
}

void Game::InitObjects() {
    auto painter = Painter::GetPainter();

    Player* player = new Player(0.25, 0.5, this);
    PlayerView* player_view = (PlayerView*) ViewFactory::CreateView(player, painter);

    player->view = player_view;

    for (int i = 0; i < 20000; i++) {
        Stick* stick = new Stick(); 
        AddObject(stick);
        StickView* stick_view = new StickView(stick, painter);
        painter->AddView(stick_view);

        player->GetBackpack()->AddItem(stick);
    }

    BackpackView* backpack_view = new BackpackView(player->GetBackpack(), player);
    painter->AddView(backpack_view);

    
    AddObject(player);

    painter->AddView(player_view);
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
