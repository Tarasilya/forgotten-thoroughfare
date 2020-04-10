#include "stick.h"

#include "collisions/null_collision_box.h"
#include "objects/items/item.h"
#include "painter/painter.h"
#include "views/texture_view.h"

Stick::Stick() : Item(false, ItemType::STICK), name_("stick") {
    View* view = (new TextureView("pics/stick_cool.png", this))
        ->SetZ(1)
        ->SetSize(ITEM_SIZE, ITEM_SIZE)
        ->SetVisibility(this);
    Painter::GetPainter()->AddView(view);
}

void Stick::Tick(double dt){
	return;
}
