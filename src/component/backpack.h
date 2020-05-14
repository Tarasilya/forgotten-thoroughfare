#pragma once

#include "component.h"
#include "visibility.h"

#include <map>
#include <string>


class Entity;

namespace component {

const std::string APPLE = "apple";
const std::string STICK = "stick";
const std::string STONE = "stone";
const std::string CIDER = "cider";
const std::string SWORD = "apple";

class Backpack: public Component, public Visibility {
private:
    std::map<std::string, int> items_; 
    Entity* entity_ = 0;

public:
    void AddItem(const std::string& item);
    void RemoveItem(const std::string& item);
    std::map<std::string, int>& GetItems();

    void SetEntity(Entity* entity);
    Entity* GetEntity();
    void RemoveEntity();
    std::string ToString();
};

}
