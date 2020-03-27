#pragma once

#include "objects/game_object.h"
#include "views/player_view.h"
#include "collisions/rect_collision_box.h"

enum ItemType{STICK, APPLE, STONE};

/*
	Null collision box whenever visibility is false and vice versa
	Should not access x_ and y_ if not visible
*/

class Item : public GameObject {
private:   
    double x_;
    double y_;
    CollisionBox* collision_box_;    
    bool visibility_;
    ItemType type_;

public:
	Item(bool visibility, ItemType type);
	bool GetVisibility();
	ItemType GetItemType();
	double GetX();
	double GetY();

};