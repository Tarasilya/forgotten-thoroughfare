#include "objects/items/sword/sword.h"

Sword::Sword() : Item(false, ItemType::SWORD), name_("sword") {}

void Sword::Tick(double dt){
	return;
}

bool Sword::Craftable() {
	return true;
}