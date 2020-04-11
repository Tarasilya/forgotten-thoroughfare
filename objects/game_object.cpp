#include "game_object.h"

#include "core/game.h"

GameObject::GameObject() {
    Game::GetGame()->AddObject(this);
}


bool GameObject::Pickupable(Player* p) {
    return false;
}