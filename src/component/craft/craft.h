#pragma once

#include "component/backpack.h"
#include "component/component.h"
#include "component/has_entity.h"
#include "recipe.h"

#include <string>

namespace component {
class Backpack;
}
class Entity;

namespace component {

class Craft: public Component, public HasEntity {
private:
    std::map<std::string, Recipe> recipes_;
    std::string selected_;
public:
    bool visibility = false;

    Craft(std::map<std::string, Recipe> recipes);
    const Recipe& GetRecipe(const std::string& item);
    std::string ToString();

    void UpdateView(Backpack* backpack);

    const std::string& GetSelected();
    void SelectNext();
    void SelectPrevious();

    static std::string CraftMenuString(Craft* craft, Backpack* backpack);
};

}
