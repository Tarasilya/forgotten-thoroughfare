#include "tile_view.h"

#include "collisions/null_collision_box.h"
#include "painter/painter.h"
#include "views/texture_view.h"

TileView* TileView::CreateTileView(double x, double y, char type, Painter* painter) {
    switch(type) {
        case '@':
            return new TileView(x, y, "pics/water.jpg", painter);
            break;
        case '.':
            return new TileView(x, y, "pics/sand.jpg", painter);
            break;
        case '*':
            return new TileView(x, y, "pics/forest.jpg", painter);
            break;
    }    
}

TileView::TileView(double x, double y, std::string filename, Painter* painter) : TextureView(filename) {
    z_ = 0;

    SetSize(
        painter->Transform(TILE_SIZE, painter->Width()), 
        painter->Transform(TILE_SIZE, painter->Height()));

    x_ = x;
    y_ = y;

    Painter::GetPainter()->AddView(this);
}

void TileView::Draw(Painter* painter) {
    TextureView::Draw(painter, x_, y_);
}
