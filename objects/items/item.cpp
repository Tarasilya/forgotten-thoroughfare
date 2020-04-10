#include <cassert>

#include "objects/items/item.h"
#include "collisions/null_collision_box.h"

std::map<ItemType, std::string> Item::item_type_convert_ = {{STICK, "Stick"}, {APPLE, "Apple"}, {ROCK, "Rock"}, {SWORD, "Sword"}, {CIDER, "Cider"}};
std::vector<ItemType> Item::item_types_ = {STICK, APPLE, ROCK, SWORD, CIDER};

Item::Item(bool visibility, ItemType type) {
    visibility_ = visibility;
    type_ = type;
    collision_box_ = new NullCollisionBox();
    x_ = 0;
    y_ = 0;
}

bool Item::GetVisibility() {
    return visibility_;
}

ItemType Item::GetType() {
    return type_;
}

double Item::GetX() {
    return x_;
}

double Item::GetY() {
    return y_;
}


CollisionBox* Item::GetCollisionBox() const {
    return collision_box_;
}

std::map<ItemType, std::string> Item::GetConversionTable() {
    return item_type_convert_;
}   

void Item::Drop(double x, double y) {
    visibility_ = true;
    collision_box_ = new RectCollisionBox(x, y, x + ITEM_SIZE, y + ITEM_SIZE); 
    x_ = x;
    y_ = y;  
}

bool Item::Droppable() {
    return !visibility_;
}

bool Item::Pickupable(Player* p) {
    return true;
}

bool Item::Collidable(Player* p) {
    return true;
}

void Item::GetPicked() {
    visibility_ = false;
    x_ = 0;
    y_ = 0;
    collision_box_ = new NullCollisionBox();
}

std::vector<ItemType> Item::GetItemTypes() {
    return {APPLE, STICK, ROCK, SWORD, CIDER};
}