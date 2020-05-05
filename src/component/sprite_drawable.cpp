#include "sprite_drawable.h"


namespace component {

SpriteDrawable::SpriteDrawable(const std::string& drawable): drawable_(drawable) {}

const std::string& SpriteDrawable::GetDrawable() {
    return drawable_;
}

}