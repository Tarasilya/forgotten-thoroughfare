#include "game_object.h"

#include "core/game.h"

#include <iostream>

GameObject::GameObject() {
    Game::GetGame()->AddObject(this);
}


bool GameObject::Pickupable(Player* p) {
    return false;
}