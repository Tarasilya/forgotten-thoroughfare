#include "backpack.h"

#include <cassert>


namespace component {

void Backpack::AddItem(const std::string& item) {
    items_[item]++;
}

void Backpack::RemoveItem(const std::string& item) {
    assert(items_[item] > 0);
    items_[item]--;
}

std::map<std::string, int>& Backpack::GetItems() {
    return items_;
}

std::string Backpack::ToString() {
    return "backpack";
}

void Backpack::SetEntity(Entity* entity) {
    entity_ = entity;
}

Entity* Backpack::GetEntity() {
    return entity_;
}

void Backpack::RemoveEntity() {
    entity_ = 0;
}

}
