#include "backpack/backpack.h"

Backpack::Backpack(){
	return;
}

std::vector<Item*> Backpack::GetItems() {
	return items_;
}


void Backpack::AddItem(Item* item) {
	items_.push_back(item);
}