#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class CollisionBox;
class DisplayableObject;
class NullCollisionBox;
class TextureView;

class Map {
private:

    static DisplayableObject* CreateTile(double x, double y, char type);
public:
    Map(std::string filename);
};
