#include "punching_bag_view.h"

#include "painter/painter.h"
#include "objects/punching_bag.h"
#include "collisions/rect_collision_box.h"


PunchingBagView::PunchingBagView(PunchingBag* bag) : TextureView("pics/punch_bag.png"), bag_(bag) {
    z_ = 1;
    // THAT'S REAL DIRTY DOWN THERE
    RectCollisionBox* box = (RectCollisionBox*) bag->GetCollisionBox();


    Painter* painter = Painter::GetPainter();
    SetSize(
        painter->Transform(box->x2 - box->x1, painter->Width()), 
        painter->Transform(box->y2 - box->y1, painter->Height()));
}
void PunchingBagView::Draw(Painter* painter) {
    TextureView::Draw(painter, bag_->GetX(), bag_->GetY());
}
