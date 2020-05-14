#pragma once

#include <map>
#include <string>

class Recipe {
private:
    std::map<std::string, int> recipe_;
public:
    Recipe();
    Recipe(std::map<std::string, int> recipe);
    bool IsEnough(std::map<std::string, int> items);
};