#include "craft.h"

#include "component/backpack.h"
#include "component/text.h"
#include "entity.h"

#include <iostream>


namespace component {

Craft::Craft(std::map<std::string, Recipe> recipes)
        : recipes_(recipes) {
    selected_ = recipes_.begin()->first;
}

const Recipe& Craft::GetRecipe(const std::string& item) {
    return recipes_[item];
}

std::string Craft::ToString() {
    return "craft";
}

void Craft::SelectNext() {
    std::cerr << selected_ << std::endl;
    auto it = recipes_.find(selected_);
    it++;
    if (it == recipes_.end()) {
        it = recipes_.begin();
    }
    selected_ = it->first;
    std::cerr << selected_ << std::endl;
}

void Craft::SelectPrevious() {
    auto it = recipes_.find(selected_);
    if (it == recipes_.begin()) {
        it = recipes_.end();
    }
    it--;
    selected_ = it->first;
}

const std::string& Craft::GetSelected() {
    return selected_;
}

void Craft::UpdateView(Backpack* backpack) {
    Entity* entity = GetEntity();
    assert(entity != 0);
    entity
        ->GetComponent<component::Text>()
        ->SetText(component::Craft::CraftMenuString(this, backpack));
}

std::string Craft::CraftMenuString(Craft* craft, Backpack* backpack) {
    std::string result = "";
    int i = 0;
    for (auto const& [item, recipe]: craft->recipes_) {
        result += std::to_string(i+1) + ". " + item + "\n";
        if (item == craft->selected_) {
            for (auto const& [item, count]: recipe.Get()) {
                result += 
                    "  " + item + " " 
                    + std::to_string(backpack->Count(item)) 
                    + "/" + std::to_string(count) + "\n";
            }
        }
        i++;
    }
    return result;
}

}
