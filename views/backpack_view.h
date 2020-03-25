#pragma once

#include "view.h"
#include "views/text_view.h"
#include "backpack/backpack.h"
#include "objects/player.h"

#include <SFML/Graphics.hpp>

class BackpackView : public TextView {
private:
    Backpack* backpack_;
    Player* player_;
public:
    BackpackView(Backpack* backpack, Player* player);
    void Draw(Painter* painter) override;
};