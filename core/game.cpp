#include "collisions/collision_box.h"
#include "game.h"
#include "painter/painter.h"
#include "objects/rat.h"
#include "views/view.h"
#include "views/view_factory.h"


#include <iostream>
#include <cmath>
#include <sstream>

Game::Game(Painter* painter) {
    painter_ = painter;
    
    InitObjects();
}

void Game::InitObjects() {
    for (int i = 0; i < 2; i++) {
        Rat* rat = new Rat(0.25 + 0.5 * i, 0.5, i, this);
        objects_.push_back(rat);
        views_.push_back(ViewFactory::CreateView(rat, painter_));
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
    std::vector<GameObject*>* collided_objects = new std::vector<GameObject*>();
    for (auto object : objects_) {
        if (object->GetCollisionBox()->Collide(collision_box)) {
            collided_objects->push_back(object);
        }
    }
    return *collided_objects;
}
