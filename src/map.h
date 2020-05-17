#pragma once

#include <string>

namespace systems {
    class SystemManager;
}

class Entity;

enum TileType {
    STONE, ROAD_HORIZONTAL, ROAD_VERTICAL, FOREST
};

class Map {
private:
    Entity* CreateTile(double x, double y, TileType type);
public:
    Map(systems::SystemManager* manager);
};