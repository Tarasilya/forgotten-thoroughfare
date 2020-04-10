#pragma once

#include "view.h"
#include "views/text_view.h"
#include "backpack/craft.h"
#include "objects/player.h"

#include <SFML/Graphics.hpp>

CraftStage

class BackpackView : public TextView {
private:
    Player* player_;
public:
    BackpackView(Player* player);
    void Draw(Painter* painter) override;
};