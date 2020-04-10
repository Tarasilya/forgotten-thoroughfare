#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class CollisionBox;
class NullCollisionBox;
class TextureView;

class Map {
private:
    std::vector<std::vector<TextureView*>> map_;

    static TextureView* CreateTileView(double x, double y, char type);
public:
    Map(std::string filename);
};
