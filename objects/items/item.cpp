#include "objects/items/item.h"
#include "collisions/null_collision_box.h"


std::map<ItemType, std::string> Item::item_type_convert_ = {{STICK, "Stick"}, {APPLE, "Apple"}, {STONE, "Stone"}};

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


CollisionBox* Item::GetCollisionBox() {
    return collision_box_;
}

std::map<ItemType, std::string> Item::GetConversionTable() {
    return item_type_convert_;
}   
