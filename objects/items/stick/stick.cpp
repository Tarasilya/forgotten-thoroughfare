#include "objects/items/stick/stick.h"
#include "objects/items/item.h"
#include "collisions/null_collision_box.h"

Stick::Stick() : Item(false, ItemType::STICK), name_("stick") {
    View* view = new TextureView("pics/stick_cool.png", this)
        .SetZ(1)
        .SetSize(ITEM_SIZE)
        .SetVisibility(this);
    Painter::GetPainter()->AddView(view);
}

void Stick::Tick(double dt){
	return;
}
