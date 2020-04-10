#include "map.h"

#include "collisions/null_collision_box.h"
#include "core/game.h"
#include "objects/displayable_object.h"
#include "painter/painter.h"
#include "views/texture_view.h"
#include "views/position.h"

#include <fstream>
#include <cstdio>

const double TILE_SIZE = 0.17;

Map::Map(std::string filename) {
    auto painter = Painter::GetPainter();
    std::ifstream in (filename);
    std::string row;
    int i = 0;
    Game* game = Game::GetCurrentGame();

    int height, width;

    in >> height >> width;

    while(in >> row) {
        int j = 0;
        for(char c : row) {
            double x = (j - width / 2) * TILE_SIZE;
            double y = (i - height / 2) * TILE_SIZE;
            game->AddObject(CreateTile(x, y, c));
            j++;
        }
        i++;
    }
}

DisplayableObject* Map::CreateTile(double x, double y, char type) {
    TextureView* view;
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
    DisplayableObject* tile = 
        (new DisplayableObject(
            filename, type != '@', new RectCollisionBox(x, y, x + TILE_SIZE, y + TILE_SIZE))
        )->WithZ(0);
    return tile;
}