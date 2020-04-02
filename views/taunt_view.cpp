#include "painter/painter.h"
#include "objects/items/item.h"
#include "player_view.h"
#include "collisions/rect_collision_box.h"
#include "views/taunt_view.h"

#include <iostream>
#include <cstdio>

TauntView::TauntView(Taunt* taunt, Painter* painter) : TextureView("pics/taunt2.png"), taunt_(taunt) {
    // THAT'S REAL DIRTY DOWN THERE
    RectCollisionBox* box = (RectCollisionBox*) taunt->GetCollisionBox();
    z_ = 4;

    SetSize(
        	painter->Transform(0.05, painter->Width()), 
        	painter->Transform(0.05, painter->Height()));

}

void TauntView::Draw(Painter* painter) {
	
	if (taunt_->GetVisibility()) {
	    TextureView::Draw(painter, taunt_->GetPlayer()->GetX() - 0.05 + taunt_->GetX(), taunt_->GetPlayer()->GetY() + 0.05 + taunt_->GetY());
	}
}
