#pragma once

#include "component/component.h"

#include <deque>
#include <string>
#include <vector>


namespace systems {
    class SystemManager;
}
class Entity;

namespace component {


const double TILE_SIZE = 0.09;

enum TileType {
    STONE, ROAD_HORIZONTAL, ROAD_VERTICAL, FOREST
};

class Map: public Component {
private:
    int rows_;
    int columns_;
    std::vector<std::vector<Entity*>> map_;

    Entity* CreateTile(double x, double y, TileType type);
    std::pair<int, int> GetCoords(Entity* tile);
public:
    Map(systems::SystemManager* manager, std::string filename);

    std::deque<Entity*> GetPath(Entity* from, Entity* to);
};

}
