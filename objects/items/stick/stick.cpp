#include "objects/items/stick/stick.h"
#include "objects/items/item.h"
#include "collisions/null_collision_box.h"

Stick::Stick() : Item(false, ItemType::STICK), name_("stick") {}

CollisionBox* Stick::GetCollisionBox() {
	return new NullCollisionBox();
}

