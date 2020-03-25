#include "backpack_view.h"

#include "painter/painter.h"

#include <cstdio>
#include <iostream>
#include <stdlib.h>

BackpackView::BackpackView(Backpack* backpack, Player* player) : TextView("Empty Backpack") {
	std::cerr << "Here b \n";
	backpack_ = backpack; 
	player_ = player;
	std::cerr << "Here a\n";
    // SetText("8========>");
}

void BackpackView::Draw(Painter* painter) {
    SetCoords(player_->GetX(), player_->GetY());
    if (player_->GetBackpackVisibility()) {
    	painter->Draw(*GetText());
    }
}