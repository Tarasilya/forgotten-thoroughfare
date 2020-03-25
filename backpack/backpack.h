#pragma once

#include "views/player_view.h"
#include "objects/items/item.h"
#include <vector>

class Backpack {
private:
    std::vector<Item*> items;
public:
    Backpack();
    void AddItem(Item* item);
    void Display();
};