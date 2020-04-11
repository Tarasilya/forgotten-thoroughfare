#include "apple.h"

#include "collisions/null_collision_box.h"
#include "objects/items/item.h"
#include "painter/painter.h"
#include "views/texture_view.h"

Apple::Apple() : Item(false, ItemType::APPLE), name_("apple") {
    (new TextureView("pics/apple.png", this))
        ->SetSize(ITEM_SIZE, ITEM_SIZE)
        ->SetVisibility(this)
        ->SetZ(1);
}

void Apple::Tick(double dt){
	return;
}

bool Apple::Craftable() {
	return false;
}