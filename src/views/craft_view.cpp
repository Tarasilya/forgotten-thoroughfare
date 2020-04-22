#include "craft_view.h"

#include "painter/painter.h"
#include "objects/items/item.h"

#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

const int first_column = 15;


std::string operator*(const std::string& s, unsigned int n) {
    std::stringstream out;
    while (n--)
        out << s;
    return out.str();
}

std::string operator*(unsigned int n, const std::string& s) { return s * n; }


CraftView::CraftView(Backpack* backpack, Player* player) : TextView("") {
	SetZ(2);
	backpack_ = backpack; 
	player_ = player;
	current_item_ = 0;
}

void CraftView::Draw(Painter* painter) {
	std::string craft_string = "";

	std::vector<ItemType> craftables = Item::GetCraftableTypes();

	for (int i = 0; i < craftables.size(); i++) {
		ItemType current_craftable = craftables[i];
		std::string current_row = "";
		
		// Index of a craftable
		current_row += std::to_string(i) + ". ";
		// Name of a craftable
		current_row += Item::GetConversionTable()[current_craftable];
		if (i == current_item_) {
			current_row += "   Recipe: \n" + RecipeSummary(current_craftable);
		}
		else {	
			current_row += "\n";
		}
		craft_string += current_row;
	}
		

	SetText(craft_string);

    SetCoords(player_->GetX(), player_->GetY());
    if (player_->GetInfoStatus() == InfoStatus::CRAFT_MENU) {
    	painter->Draw(*GetText());
    }
}

std::string CraftView::RecipeSummary(ItemType item_type) {
	std::vector<ItemType> basics = Item::GetBasicTypes();

	std::map<ItemType, int> recipe = Craft::GetRecipe(item_type);

	std::map<ItemType, int> current_backpack = Craft::CountItems(player_);

	std::string recipe_string = "";
	for (int i = 0; i < basics.size(); i++) {
		std::string current_row = "----";
		ItemType current_basic = basics[i];
		current_row += Item::GetConversionTable()[current_basic] + "  ";
		current_row += std::to_string(current_backpack[current_basic]);
		current_row += "/";
		current_row += std::to_string(recipe[current_basic]);
		current_row += "\n";
		recipe_string += current_row;
	}
	return recipe_string;
}

void CraftView::ChangeCurrentItem() {
	current_item_ = (current_item_ + 1) % Item::GetCraftableTypes().size();
}

int CraftView::GetCurrentItem() {
	return current_item_;
}