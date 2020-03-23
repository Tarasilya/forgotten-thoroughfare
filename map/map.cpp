#include "map.h"

#include "collisions/null_collision_box.h"

Map::Map(std::string filename) {
    std::ifstream in (filename);
    string row;
    int i = 0;
    while(in >> row) {
        int j = 0;
        for(char c : row) {
            map.back().push_back(CreateTile(c, i, j));
            j++;
        }
        i++;
    }
}

Tile* Map::CreateTile(char c) {
    switch(c) {
        case ' ':
            return new WaterTile();
            break;
        case '.':
            return new SandTile();
            break;
        case '*':
            return new ForestTile();
            break;
    }
}

CollisionBox* Map::GetCollisionBox() {
    return new NullCollisionBox();
}

Map::Tick(double dt) {}

Map::ProcessKey(sf::Keyboard::Key key, bool pressed) {
    return false;
}
