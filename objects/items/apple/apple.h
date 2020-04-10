#pragma once

#include <stdlib.h>

#include "objects/game_object.h"
#include "objects/items/item.h"

class Apple : public Item {
private:   
    std::string name_;
public:
	Apple();
    std::string GetName();

    void Tick(double dt) override;
    bool Craftable() override;
};