#include "map.h"

#include "collisions/null_collision_box.h"
#include "core/game.h"
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
        map_.push_back(std::vector<TextureView*>());
        for(char c : row) {
            double x = (j - width / 2) * TILE_SIZE;
            double y = (i - height / 2) * TILE_SIZE;
            map_.back().push_back(CreateTileView(x, y, c));
            j++;
        }
        i++;
    }
}

TextureView* Map::CreateTileView(double x, double y, char type) {
    TextureView* view;
    switch(type) {
        case '@':
            view = new TextureView("pics/water.jpg", new Position(x, y));
            break;
        case '.':
            view = new TextureView("pics/sand.jpg", new Position(x, y));
            break;
        case '*':
            view = new TextureView("pics/forest.jpg", new Position(x, y));
            break;
    }    
    view->SetZ(0)->SetSize(TILE_SIZE, TILE_SIZE);
    Painter::GetPainter()->AddView(view);
    return view;    
}