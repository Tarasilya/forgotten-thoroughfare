#include "player_view.h"

#include "objects/player.h"

PlayerView::PlayerView(Player* player): TextureView("pics/cider_warrior3.png", this), player_(player) {
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

double PlayerView::GetX() {
    return player_->GetX() + (direction_ == -1) * PLAYER_SIZE;
}


double PlayerView::GetY() {
    return player_->GetY();
}
