#pragma once

#include "objects/items/item.h"
#include <vector>
#include <map>

class Player;

class Craft{
private:
	static std::map<ItemType, std::map<ItemType, int>> crafting_recipes_; 
public:
	Craft() = delete;
	static void Initialize();
	static void CraftItem(ItemType requested_item, Player* p);
	static bool CheckIngredients(std::map<ItemType, int> crafting_requirement, Player* p);
	static void TakeIngredients(std::map<ItemType, int> crafting_requirement, Player* p);
};