#pragma once

#include "view.h"
#include "views/text_view.h"
#include "backpack/craft.h"
#include "objects/player.h"

#include <SFML/Graphics.hpp>

class CraftView : public TextView {
private:
	Backpack* backpack_;
    Player* player_;
    int current_item_;
public:
    CraftView(Backpack* backpack, Player* player);
    void Draw(Painter* painter) override;
    void ChangeCurrentItem();
    int GetCurrentItem();
    std::string RecipeSummary(ItemType item_type);
};