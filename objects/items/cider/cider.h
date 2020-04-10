#pragma once

#include <stdlib.h>

#include "objects/game_object.h"
#include "objects/items/item.h"

class Cider : public Item {
private:   
    std::string name_;
public:
	Cider();
    std::string GetName();

    void Tick(double dt) override;
    bool Craftable() override;
};