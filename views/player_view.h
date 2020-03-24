#pragma once

#include "texture_view.h"

class Player;

class PlayerView : public TextureView {
private:
    Player* player_;
public:
    PlayerView(Player* player, Painter* painter);
    void Draw(Painter* painter) override;
};