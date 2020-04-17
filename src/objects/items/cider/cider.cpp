#include "cider.h"

#include "collisions/null_collision_box.h"
#include "objects/items/item.h"
#include "painter/painter.h"
#include "views/texture_view.h"

Cider::Cider() : Item(false, ItemType::CIDER), name_("cider") {
    (new TextureView("pics/craft_cider.png", this))
        ->SetSize(ITEM_SIZE, ITEM_SIZE)
        ->SetVisibility(this)
        ->SetZ(1);
}

void Cider::Tick(double dt){
	return;
}

bool Cider::Craftable() {
	return true;
}