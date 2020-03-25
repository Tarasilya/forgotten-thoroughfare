#include "rat_view.h"

#include "objects/rat.h"
#include "painter/painter.h"
#include "collisions/rect_collision_box.h"

#include <iostream>
#include <cstdio>

RatView::RatView(Rat* rat, Painter* painter) : TextureView("pics/mouse_assassin.jpg"), rat_(rat) {
    z_ = 1;
    // THAT'S REAL DIRTY DOWN THERE
    RectCollisionBox* box = (RectCollisionBox*) rat->GetCollisionBox();

    SetSize(
        painter->Transform(box->x2 - box->x1, painter->Width()), 
        painter->Transform(box->y2 - box->y1, painter->Height()));
}
void RatView::Draw(Painter* painter) {
    TextureView::Draw(painter, rat_->GetX(), rat_->GetY());
}
