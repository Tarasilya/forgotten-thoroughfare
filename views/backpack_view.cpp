#include "backpack_view.h"

#include "painter/painter.h"

#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string>

BackpackView::BackpackView(Backpack* backpack, Player* player) : TextView("Empty Backpack") {
	SetZ(2);
	backpack_ = backpack; 
	player_ = player;
}

void BackpackView::Draw(Painter* painter) {
	if (backpack_->GetItems().empty()) {
		SetText("Backpack: \n Empty");
	}
	else {
		std::string backpack_content = "Backpack: \n";
		std::map<ItemType, int> current_content = {{STICK, 0}, {APPLE, 0}, {STONE, 0}};

		for (auto item : backpack_->GetItems()) {
			current_content[item->GetType()] += 1;
		}

		for (const auto &type_qty : current_content ) {
			backpack_content += Item::GetConversionTable()[type_qty.first] + " " + std::to_string(type_qty.second) + "\n";
		}

		SetText(backpack_content);
	}

    SetCoords(player_->GetX(), player_->GetY());
    if (player_->GetBackpackVisibility()) {
    	painter->Draw(*GetText());
    }
}