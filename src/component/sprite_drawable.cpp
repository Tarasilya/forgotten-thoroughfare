#include "sprite_drawable.h"


SpriteDrawable::SpriteDrawable(const std::string& drawable): drawable_(drawable) {}

SpriteDrawable::~SpriteDrawable() {}

const std::string& SpriteDrawable::GetDrawable() {
    return drawable_;
}
