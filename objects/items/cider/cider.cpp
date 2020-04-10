#include "objects/items/cider/cider.h"

Cider::Cider() : Item(false, ItemType::CIDER), name_("cider") {}

void Cider::Tick(double dt){
	return;
}

bool Cider::Craftable() {
	return true;
}