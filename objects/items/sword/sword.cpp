#include "sword.h"

#include "collisions/null_collision_box.h"
#include "objects/items/item.h"
#include "painter/painter.h"
#include "views/texture_view.h"

Sword::Sword() : Item(false, ItemType::SWORD), name_("sword") {
    (new TextureView("pics/cool_sword.png", this))
        ->SetSize(2*ITEM_SIZE, 2*ITEM_SIZE)
        ->SetVisibility(this)
        ->SetZ(1);
}

void Sword::Tick(double dt){
	return;
}

bool Sword::Craftable() {
	return true;
}