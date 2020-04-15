#include "game_object.h"

#include "core/game.h"

#include <iostream>

GameObject::GameObject() {
    std::cerr << "QQQ" << std::endl;
    Game::GetGame()->AddObject(this);
}


bool GameObject::Pickupable(Player* p) {
    return false;
}