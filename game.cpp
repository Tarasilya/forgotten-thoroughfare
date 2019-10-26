#include "collision_box.h"
#include "game.h"
#include "painter.h"
#include "player.h"
#include "rat_view.h"
#include "view.h"


#include <iostream>
#include <cmath>
#include <sstream>

Game::Game(Painter* painter) {
    painter_ = painter;
    
    InitObjects();
}

void Game:InitObjects() {
    for (int i = 0; i < 2; i++) {
        Rat* rat = new Rat(0.25 + 0.5 * i, 0.5, i);
        RatView* rat_view = new RatView(rat);
        objects_.push_back(rat);
        views_.push_back(rat_view);
    }
}

void Game::Draw() {
    for (auto view : views_) {
        view->Draw(painter_);
    }
}

void Game::ProcessKey(sf::Keyboard::Key key)
{
    for (auto object : objects_) {
        if (object->ProcessKey(key)) {
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
    std::vector<GameObject*> collided_objects = new vector<GameObject*>();
    for (auto object : objects_) {
        if (object->GetCollisionBox()->collide(collision_box)) {
            collided_objects.append(object);
        }
    }
    return collided_objects;
}
