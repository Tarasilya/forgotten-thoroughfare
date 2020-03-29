#pragma once

#include "objects/passive_object.h"
#include "views/player_view.h"
#include "collisions/rect_collision_box.h"

enum ItemType{STICK, APPLE, STONE};

/*
	Null collision box whenever visibility is false and vice versa
	Should not access x_ and y_ if not visible
*/

class Item : public PassiveObject {
private:   
    double x_;
    double y_;
    CollisionBox* collision_box_;    
    bool visibility_;
    ItemType type_;

	static std::map<ItemType, std::string> item_type_convert_;


public:
	Item(bool visibility, ItemType type);
	bool GetVisibility();
	ItemType GetType();

	static std::map<ItemType, std::string> GetConversionTable();	

    CollisionBox* GetCollisionBox() override;
	double GetX();
	double GetY();

};
