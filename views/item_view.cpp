#include "painter/painter.h"
#include "objects/items/item.h"
#include "player_view.h"
#include "collisions/rect_collision_box.h"
#include "views/item_view.h"

#include <iostream>
#include <cstdio>

ItemView::ItemView(Item* item, Painter* painter, const std::string& filename) : TextureView(filename), item_(item) {
    // THAT'S REAL DIRTY DOWN THERE
    RectCollisionBox* box = (RectCollisionBox*) item->GetCollisionBox();

    SetSize(
        painter->Transform(box->x2 - box->x1, painter->Width()), 
        painter->Transform(box->y2 - box->y1, painter->Height()));
}

void ItemView::Draw(Painter* painter) {
	if (item_->GetVisibility()) {
	    TextureView::Draw(painter, item_->GetX(), item_->GetY());
	}
}
