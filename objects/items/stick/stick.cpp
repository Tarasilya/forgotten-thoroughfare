#include "objects/items/stick/stick.h"
#include "collisions/null_collision_box.h"

Stick::Stick() : name_("stick") {}

CollisionBox* Stick::GetCollisionBox() {
	return new NullCollisionBox();
}

