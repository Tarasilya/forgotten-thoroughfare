#pragma once

#include "component/component.h"
#include "component/visibility.h"
#include "recipe.h"


class Entity;

namespace component {

class Craft: public Component, public Visibility {
private:
    std::map<std::string, Recipe> recipes_;
    Entity* entity_; 
public:
    bool visibility = false;

    Craft(std::map<std::string, Recipe> recipes);
    const Recipe& GetRecipe(const std::string& item);
    std::string ToString();

    void SetEntity(Entity* entity);
    Entity* GetEntity();
    void RemoveEntity();    
};

}
