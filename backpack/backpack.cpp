#include "backpack/backpack.h"
#include <cassert>

Backpack::Backpack(){
	return;
}

std::vector<Item*> Backpack::GetItems() {
	return items_;
}


void Backpack::AddItem(Item* item) {
	items_.push_back(item);
}

void Backpack::DropItem(double x, double y) {
	if (! items_.empty()) {
		Item* item_to_drop = items_.back();
		items_.pop_back();
		assert(item_to_drop->Droppable());
		item_to_drop->Drop(x, y);
	}
}