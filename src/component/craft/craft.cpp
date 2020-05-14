#include "craft.h"


namespace component {

Craft::Craft(std::map<std::string, Recipe> recipes)
        : recipes_(recipes), entity_(0) {}

const Recipe& Craft::GetRecipe(const std::string& item) {
    return recipes_[item];
}

std::string Craft::ToString() {
    return "craft";
}

void Craft::SetEntity(Entity* entity) {
    entity_ = entity;
}

Entity* Craft::GetEntity() {
    return entity_;
}

void Craft::RemoveEntity() {
    entity_ = 0;
}

}
