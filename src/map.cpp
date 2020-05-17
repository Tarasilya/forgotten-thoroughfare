#include "map.h"

#include "entity.h"
#include "component/collision_rect.h"
#include "component/sprite.h"
#include "component/transform.h"
#include "component/unpassable.h"
#include "system/system_manager.h"

#include <fstream>


const double TILE_SIZE = 0.13;
const int ROWS = 10;
const int COLUMNS = 10;

Map::Map(systems::SystemManager* manager) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            double x = (j * 2 - ROWS) * TILE_SIZE;
            double y = (i * 2 - COLUMNS) * TILE_SIZE;
            manager->AddEntity(CreateTile(x, y, STONE));
            manager->AddEntity(CreateTile(x + TILE_SIZE, y, ROAD_HORIZONTAL));
            manager->AddEntity(CreateTile(x, y + TILE_SIZE, ROAD_VERTICAL));
            manager->AddEntity(
                CreateTile(x + TILE_SIZE, y + TILE_SIZE, FOREST));
        }
    }
}

Entity* Map::CreateTile(double x, double y, TileType type) {
    std::string filename;
    switch(type) {
        case STONE:
            filename = "pics/stones.jpg";
            break;
        case ROAD_VERTICAL:
            filename = "pics/road_vertical.jpg";
            break;
        case ROAD_HORIZONTAL:
            filename = "pics/road_horizontal.jpg";
            break;
        case FOREST:
            filename = "pics/forest.jpg";
            break;
    }   
    Entity* tile = new Entity("tile");
    tile->AddComponent(new component::Transform(x, y));
    tile->AddComponent(new component::Sprite(filename, TILE_SIZE, TILE_SIZE, 0));
    return tile;
}

