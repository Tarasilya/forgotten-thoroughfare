#include "map.h"

#include "entity.h"
#include "component/collision_rect.h"
#include "component/selectable.h"
#include "component/sprite.h"
#include "component/transform.h"
#include "component/unpassable.h"
#include "component/rectangle.h"
#include "system/system_manager.h"

#include <fstream>


std::map<char, TileType> char_to_type = {
    {'*', FOREST},
    {'-', ROAD_HORIZONTAL},
    {'|', ROAD_VERTICAL},
    {'o', STONE},
};

Map::Map(systems::SystemManager* manager, std::string filename) {
    std::ifstream in (filename);
    std::vector<std::string> input;
    std::string row;
    while(in >> row) {
        input.push_back(row);
        assert (row.length() == input[0].length()
            && "Rows in map are different length");
    }
    int rows = input.size();
    int columns = input[0].length();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            double x = (j - rows / 2) * TILE_SIZE;
            double y = (i - columns / 2) * TILE_SIZE;

            auto tile = CreateTile(x, y, char_to_type[input[i][j]]);
            manager->AddEntity(tile);
            if (i == rows - 1 && j == columns - 1) {
                std::cerr << "THE TILE " << x << " " << y << std::endl;
            }
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
    tile->AddComponent(new component::CollisionRect(TILE_SIZE, TILE_SIZE));
    tile->AddComponent(new component::Sprite(filename, TILE_SIZE, TILE_SIZE, 0));
    if (type != FOREST) {
        tile->AddComponent(new component::Selectable());
    }
    return tile;
}

