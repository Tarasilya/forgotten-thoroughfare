#pragma once

#include "objects/passive_object.h"
#include "views/visible.h"
#include "views/position.h"
#include "collisions/rect_collision_box.h"
#include <vector>

const double ITEM_SIZE = 0.07;

enum ItemType{STICK, APPLE, ROCK, SWORD, CIDER};

/*
	Null collision box whenever visibility is false and vice versa
	Should not access x_ and y_ if not visible
*/

class Item : public PassiveObject, public Visible, public Position {
private:   
    double x_;
    double y_;
    CollisionBox* collision_box_;    
    bool visibility_;
    ItemType type_;

	static std::map<ItemType, std::string> item_type_convert_;
	static std::vector<ItemType> item_types_;

public:
	Item(bool visibility, ItemType type);
	bool GetVisibility() override;
	ItemType GetType();

	static std::map<ItemType, std::string> GetConversionTable();	
	static std::vector<ItemType> GetItemTypes();
	static std::vector<ItemType> GetBasicTypes();
	static std::vector<ItemType> GetCraftableTypes();

    CollisionBox* GetCollisionBox() const override;
	double GetX() override;
	double GetY() override;
	void Drop(double x, double y);
	void GetPicked();
	bool Droppable();
	bool Pickupable(Player* p) override;
	bool Collidable(Player* p) override;
	virtual bool Craftable() = 0;
};
