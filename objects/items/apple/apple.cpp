#include "objects/items/apple/apple.h"
#include "objects/items/item.h"

Apple::Apple() : Item(false, ItemType::APPLE), name_("apple") {}

void Apple::Tick(double dt){
	return;
}

bool Apple::Craftable() {
	return false;
}