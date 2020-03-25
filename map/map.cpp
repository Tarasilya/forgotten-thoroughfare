#include "map.h"

#include "collisions/null_collision_box.h"
#include "core/game.h"
#include "painter/painter.h"
#include "tile_view.h"

#include <fstream>
#include <cstdio>

Map::Map(std::string filename) {
    auto painter = Painter::GetPainter();
    std::ifstream in (filename);
    std::string row;
    int i = 0;
    Game* game = Game::GetCurrentGame();
    while(in >> row) {
        int j = 0;
        map_.push_back(std::vector<TileView*>());
        for(char c : row) {
            double x = j * TILE_SIZE;
            double y = i * TILE_SIZE;
            map_.back().push_back(TileView::CreateTileView(x, y, c, painter));
            j++;
        }
        i++;
    }
}

CollisionBox* Map::GetCollisionBox() {
    return new NullCollisionBox();
}

void Map::Tick(double dt) {}

bool Map::ProcessKey(sf::Keyboard::Key key, bool pressed) {
    return false;
}
