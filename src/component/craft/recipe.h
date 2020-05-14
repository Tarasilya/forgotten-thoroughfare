#pragma once

#include <map>
#include <string>

class Recipe {
private:
    std::map<std::string, int> recipe_;
public:
    Recipe();
    Recipe(std::map<std::string, int> recipe);
    const std::map<std::string, int>& Get() const;
    bool IsEnough(std::map<std::string, int> items);
};