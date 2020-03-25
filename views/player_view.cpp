#include "player_view.h"

#include "painter/painter.h"
#include "objects/player.h"
#include "collisions/rect_collision_box.h"

#include <iostream>
#include <cstdio>

PlayerView::PlayerView(Player* player, Painter* painter) : TextureView("pics/mouse_assassin.jpg"), player_(player) {
    z_ = 1;
    // THAT'S REAL DIRTY DOWN THERE
    RectCollisionBox* box = (RectCollisionBox*) player->GetCollisionBox();

    SetSize(
        painter->Transform(box->x2 - box->x1, painter->Width()), 
        painter->Transform(box->y2 - box->y1, painter->Height()));
}
void PlayerView::Draw(Painter* painter) {
    TextureView::Draw(painter, player_->GetX(), player_->GetY());
}
