#pragma once

#include "texture_view.h"

class Player;

class PlayerView : public TextureView {
private:
    int direction_ = 1;
    Player* player_;
public:
    PlayerView(Player* p);
    void Draw(Painter* painter) override;
};
