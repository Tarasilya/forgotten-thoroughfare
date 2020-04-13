#include "player_view.h"

#include "objects/player.h"

PlayerView::PlayerView(Player* player): TextureView("pics/sword_warrior2.png", player), player_(player) {
    SetZ(1);
    SetSize(PLAYER_SIZE, PLAYER_SIZE);
}

void PlayerView::Draw(Painter* painter) {
    int current_direction = player_->GetDirection();
    if (current_direction != direction_) {
        sprite_->scale(-1, 1);
        direction_ = current_direction;
    }
    TextureView::Draw(painter);
}