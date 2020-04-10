#include "backpack/craft.h"
#include "objects/player.h"
#include "objects/items/sword/sword.h"

std::map<ItemType, std::map<ItemType, int>> Craft::crafting_recipes_;

void Craft::Initialize() {

	crafting_recipes_ = {	{	SWORD, {{STICK, 3}, {APPLE, 0}, {ROCK, 0}}	}	};

}

void Craft::CraftItem(ItemType requested_item, Player* p) {
	std::map<ItemType, int> crafting_requirement = crafting_recipes_[requested_item];


	if ( CheckIngredients(crafting_requirement, p) ) {
		TakeIngredients(crafting_requirement, p);
		Item* item_to_craft;
		switch(requested_item) {
			case SWORD:
				item_to_craft = new Sword();
		}
		p->GetBackpack()->AddItem(item_to_craft);
	}
}

bool Craft::CheckIngredients(std::map<ItemType, int> crafting_requirement, Player* p) {
	std::map<ItemType, int> current_backpack_content;

	for (auto item_type : Item::GetItemTypes()) {
		current_backpack_content[item_type] = 0;
	}
	for (auto item : p->GetBackpack()->GetItems()) {
		current_backpack_content[item->GetType()] += 1;
	}

	for (const auto &item_type_qty : crafting_requirement) {
		if (item_type_qty.second > current_backpack_content[item_type_qty.first]){
			return false;
		}
	}
	return true;
}

void Craft::TakeIngredients(std::map<ItemType, int> crafting_requirement, Player* p) {
	for (const auto &item_type_qty : crafting_requirement) {
		for (int i = 0; i < item_type_qty.second; i++) {
			p->GetBackpack()->RemoveItem(item_type_qty.first);
		}
	}
}
