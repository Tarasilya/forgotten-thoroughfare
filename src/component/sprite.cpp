#include "sprite.h"


namespace component {

Sprite::Sprite(const std::string& drawable, 
    double width, double height, int layer)
        : drawable_(drawable), size_({width, height}), layer_(layer) {}

const std::string& Sprite::GetDrawable() {
    return drawable_;
}

std::pair<double, double> Sprite::GetSize() {
    return size_;
}

int Sprite::GetLayer() {
    return layer_;
}

}