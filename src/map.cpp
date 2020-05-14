#include "map.h"

#include "entity.h"
#include "component/collision_rect.h"
#include "component/sprite.h"
#include "component/transform.h"
#include "component/unpassable.h"
#include "system/system_manager.h"

#include <fstream>

const double TILE_SIZE = 0.17;

Map::Map(std::string filename, systems::SystemManager* manager) {
    std::ifstream in (filename);
    std::string row;
    int i = 0;

    int height, width;

    in >> height >> width;

    while(in >> row) {
        int j = 0;
        for(char c : row) {
            double x = (j - width / 2) * TILE_SIZE;
            double y = (i - height / 2) * TILE_SIZE;
            manager->AddEntity(CreateTile(x, y, c));
            j++;
        }
        i++;
    }
}

Entity* Map::CreateTile(double x, double y, char type) {
    std::string filename;
    switch(type) {
        case '@':
            filename = "pics/water.jpg";
            break;
        case '.':
            filename = "pics/sand.jpg";
            break;
        case '*':
            filename = "pics/forest.jpg";
            break;
    }   
    Entity* tile = new Entity("tile " + std::string(1, type));
    tile->AddComponent(new component::Transform(x, y));
    tile->AddComponent(new component::Sprite(filename, TILE_SIZE, TILE_SIZE, 0));
    if (type == '@') {
        tile->AddComponent(new component::Unpassable());
        tile->AddComponent(new component::CollisionRect(TILE_SIZE, TILE_SIZE));
    }
    return tile;
}

