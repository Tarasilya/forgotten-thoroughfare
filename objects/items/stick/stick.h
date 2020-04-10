#pragma once

#include <stdlib.h>

#include "objects/game_object.h"
#include "objects/items/item.h"

class Stick : public Item {
private:   
    std::string name_;
public:
	Stick();
    std::string GetName();

    void Tick(double dt) override;
};