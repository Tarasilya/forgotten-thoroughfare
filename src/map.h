#pragma once

#include <string>

namespace systems {
    class SystemManager;
}

class Entity;

class Map {
private:
    Entity* CreateTile(double x, double y, char type);
public:
    Map(std::string filename, systems::SystemManager* manager);
};