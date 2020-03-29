#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class CollisionBox;
class NullCollisionBox;
class TileView;

class Map {
private:
    std::vector<std::vector<TileView*>> map_;

    NullCollisionBox* null_collision_box_;
public:
    Map(std::string filename);
};
