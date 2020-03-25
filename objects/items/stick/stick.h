#pragma once

#include <stdlib.h>

#include "game_object.h"
#include "views/player_view.h"

class Stick : public Item {
private:   
    std::string name_;
public:

    std::string GetName();

    CollisionBox* GetCollisionBox() override;
};