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

void Backpack::RemoveItem(ItemType type) {
	bool removed = false;
	for (int i = 0; i < items_.size(); i++) {
		if (type == items_[i]->GetType()) {
			items_.erase(begin(items_) + i);
			removed = true;
			return;
		}
	}
	// should not try to remove unexisting item
	assert(false);	
}

void Backpack::DropItem(double x, double y) {
	if (!items_.empty()) {
		Item* item_to_drop = items_.back();
		items_.pop_back();
		assert(item_to_drop->Droppable());
		item_to_drop->Drop(x, y);
	}
}

void Backpack::PickItem(Item* item) {
	AddItem(item);
	item->GetPicked();
}