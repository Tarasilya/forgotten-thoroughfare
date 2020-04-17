#pragma once

#include "texture_view.h"

#include "views/position.h"

class Player;

class PlayerView : public TextureView, public Position {
private:
    int direction_ = 1;
    Player* player_;
public:
    PlayerView(Player* p);
    void Draw(Painter* painter) override;
    double GetX() const override;
    double GetY() const override;
};
