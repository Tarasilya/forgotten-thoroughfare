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


namespace component {

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
    rows_ = input.size();
    columns_ = input[0].length();
    for (int i = 0; i < rows_; i++) {
        map_.push_back(std::vector<Entity*>(columns_));
        for (int j = 0; j < columns_; j++) {
            double x = (j - columns_ / 2) * TILE_SIZE;
            double y = (i - rows_ / 2) * TILE_SIZE;

            auto tile = CreateTile(x, y, char_to_type[input[i][j]]);
            map_[i][j] = tile;
            manager->AddEntity(tile);
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
    if (type == FOREST) {
        tile->AddComponent(new component::Unpassable());
    }
    else {
        tile->AddComponent(new component::Selectable());
    }
    return tile;
}

std::deque<Entity*> Map::GetPath(Entity* from, Entity* to) {
    std::pair<int, int> from_coords = GetCoords(from);
    std::pair<int, int> to_coords = GetCoords(to);

    std::deque<Entity*> result;
    while(from_coords.first != to_coords.first) {
        std::cerr << from_coords.first << " " << from_coords.second << std::endl;
        result.push_back(map_[from_coords.first][from_coords.second]);
        if (from_coords.first < to_coords.first) {
            from_coords.first++;
        }
        else {
            from_coords.first--;
        }
    }
    while(from_coords.second != to_coords.second) {
        std::cerr << from_coords.first << " " << from_coords.second << std::endl;
        result.push_back(map_[from_coords.first][from_coords.second]);
        if (from_coords.second < to_coords.second) {
            from_coords.second++;
        }
        else {
            from_coords.second--;
        }
    }
    result.push_back(to);
    return result;
}

std::pair<int, int> Map::GetCoords(Entity* tile) {
    auto transform = tile->GetComponent<component::Transform>();
    auto rect = tile
        ->GetComponent<component::CollisionRect>()
        ->Move(transform->GetX(), transform->GetY());

    int i = (rect.y1 + rect.y2) / 2 /TILE_SIZE + rows_ / 2;
    int j = (rect.x1 + rect.x2) / 2 /TILE_SIZE + columns_ / 2;;
    return {i, j};
}

}
