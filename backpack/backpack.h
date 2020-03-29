#pragma once

#include "views/player_view.h"
#include "objects/items/item.h"
#include <vector>

class Backpack {
private:
    std::vector<Item*> items_;
public:
    Backpack();
    std::vector<Item*> GetItems();
    void AddItem(Item* item);
    void DropItem(double x, double y); // Drops topmost item of backpack
    void Display();
};