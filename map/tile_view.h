#pragma once

#include "views/texture_view.h"

#include <string>

class CollisionBox;
class Painter;

const double TILE_SIZE = 0.17;

class TileView : public TextureView {
public:
    static TileView* CreateTileView(double x, double y, char type, Painter* painter);
    TileView(double x, double y, std::string filename, Painter* painter);
private:
    double x_;
    double y_;

    void Draw(Painter* painter);
};
