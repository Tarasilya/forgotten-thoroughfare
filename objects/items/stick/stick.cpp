#include "objects/items/stick/stick.h"
#include "objects/items/item.h"
#include "collisions/null_collision_box.h"

Stick::Stick() : Item(false, ItemType::STICK), name_("stick") {}




void Stick::Tick(double dt){
	return;
}

bool Stick::ProcessKey(sf::Keyboard::Key key, bool pressed) {
	return false;
}
