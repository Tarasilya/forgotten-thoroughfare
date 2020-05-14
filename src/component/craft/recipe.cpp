#include "recipe.h"

Recipe::Recipe() {}
Recipe::Recipe(std::map<std::string, int> recipe): recipe_(recipe) {}

bool Recipe::IsEnough(std::map<std::string, int> items) {
    for (auto const& [item, count]: recipe_) {
        if (items[item] < count) {
            return false;
        }
    }

    return true;
}

const std::map<std::string, int>& Recipe::Get() const {
    return recipe_;
}
