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
#include <queue>


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
    std::queue<std::pair<int, int>> visit_queue;
    int inf = 1e9;
    std::vector<std::vector<int>> dist (rows_, std::vector<int>(columns_, inf));
    dist[from_coords.first][from_coords.second] = 0;
    visit_queue.push(from_coords);
    int di[] = {0, 0, 1, -1};
    int dj[] = {1, -1, 0, 0};
    while (!visit_queue.empty()) {
        auto cur = visit_queue.front();
        visit_queue.pop();
        for (int i = 0; i < 4; i++) {
            std::pair<int, int> next = {cur.first + di[i], cur.second + dj[i]};
            if (next.first < 0 || next.second < 0 
                    || next.first >= rows_ || next.second >= columns_) {
                continue;
            }
            if (map_[next.first][next.second]->HasComponent<component::Unpassable>()) {
                continue;
            }
            if (dist[next.first][next.second] > dist[cur.first][cur.second] + 1) {
                dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
                visit_queue.push(next);
            }
        }
    }
    assert(dist[to_coords.first][to_coords.second] < inf && "no path to dest");
    auto cur = to_coords;
    while (cur != from_coords) {
        result.push_front(map_[cur.first][cur.second]);
        std::pair<int, int> next;
        for (int i = 0; i < 4; i++) {
            std::pair<int, int> candidate = {cur.first + di[i], cur.second + dj[i]};
            if (candidate.first < 0 || candidate.second < 0 
                    || candidate.first >= rows_ || candidate.second >= columns_) {
                continue;
            }
            if (dist[candidate.first][candidate.second] < dist[cur.first][cur.second]) {
                next = candidate;
            }
        }
        cur = next;
    }
    
    result.push_front(from);
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
