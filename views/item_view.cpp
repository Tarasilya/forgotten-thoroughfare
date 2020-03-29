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
        	painter->Transform(0.05, painter->Width()), 
        	painter->Transform(0.05, painter->Height()));

}

void ItemView::Draw(Painter* painter) {
	
	if (item_->GetVisibility()) {
		RectCollisionBox* collision_box_ = (RectCollisionBox*) item_->GetCollisionBox();
		
	    
	    TextureView::Draw(painter, item_->GetX(), item_->GetY());
	}
}
