#pragma once

#include "component.h"
#include "has_entity.h"

#include <map>
#include <string>


class Entity;

namespace component {

const std::string APPLE = "apple";
const std::string STICK = "stick";
const std::string STONE = "stone";
const std::string CIDER = "cider";
const std::string SWORD = "sword";

class Backpack: public Component, public HasEntity {
private:
    std::map<std::string, int> items_; 

public:
    void AddItem(const std::string& item, int amount = 1);
    void RemoveItem(const std::string& item, int amount = 1);
    int Count(const std::string& item);
    const std::map<std::string, int>& GetItems();

    std::string ToString();
};

}
