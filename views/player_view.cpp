#include "player_view.h"

#include "objects/player.h"

<<<<<<< HEAD
PlayerView::PlayerView(Player* player): TextureView("pics/cider_warrior3.png", this), player_(player) {
=======
PlayerView::PlayerView(Player* player): TextureView("pics/default_warrior2.png", this), player_(player) {
>>>>>>> Tmp
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

double PlayerView::GetX() const {
    return player_->GetX() + (direction_ == -1) * PLAYER_SIZE;
}


double PlayerView::GetY() const {
    return player_->GetY();
}
