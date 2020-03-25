#include "objects/items/item.h"
#include "collisions/null_collision_box.h"

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

ItemType Item::GetItemType() {
    return type_;
}