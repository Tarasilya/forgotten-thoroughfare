#include "painter.h"
#include "rat.h"
#include "rat_view.h"
#include "rect_collision_box.h"

#include <iostream>

RatView::RatView(Rat* rat, Painter* painter) : TextureView("mouse_assassin-min.jpg"), rat_(rat) {
    // THAT'S REAL DIRTY DOWN THERE
    RectCollisionBox* box = (RectCollisionBox*) rat->GetCollisionBox();
    SetSize(
        painter->Transform(box->x2 - box->x1, painter->Width()), 
        painter->Transform(box->y2 - box->y1, painter->Height()));
}
void RatView::Draw(Painter* painter) {
    TextureView::Draw(painter, rat_->GetX(), rat_->GetY());
}
