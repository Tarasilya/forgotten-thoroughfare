#include "views/stick_view.h"
#include "painter/painter.h"

StickView::StickView(Stick* stick, Painter* painter) : ItemView(stick, painter, "pics/stick_cool.png") {
    z_ = 1;
    // THAT'S REAL DIRTY DOWN THERE
    RectCollisionBox* box = (RectCollisionBox*) stick->GetCollisionBox();

    /*SetSize(
        painter->Transform(box->x2 - box->x1, painter->Width()), 
        painter->Transform(box->y2 - box->y1, painter->Height())); */
}