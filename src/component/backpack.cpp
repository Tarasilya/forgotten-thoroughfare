#include "backpack.h"

#include <cassert>


namespace component {

void Backpack::AddItem(const std::string& item, int amount) {
    items_[item] += amount;
}

void Backpack::RemoveItem(const std::string& item, int amount) {
    assert(items_[item] >= amount);
    items_[item] -= amount;
}

const std::map<std::string, int>& Backpack::GetItems() {
    return items_;
}

std::string Backpack::ToString() {
    std::string result = "backpack\n";
    for (auto const& [item, count]: items_) {
        result += item + " " + std::to_string(count) + "\n";
    }
    return result;
}

int Backpack::Count(const std::string& item) {
    return items_[item];
}

}
