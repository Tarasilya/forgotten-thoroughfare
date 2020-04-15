#include "displayable_object.h"

#include "collisions/rect_collision_box.h"
#include "objects/player/hp_bar.h"
#include "painter/painter.h"
#include "views/texture_view.h"

class View;

DisplayableObject::DisplayableObject(
    const std::string& texture_path, 
    bool collidable, 
    RectCollisionBox* collision_box
): collision_box_(collision_box) {
    view_ = (new TextureView(texture_path, this))
        ->SetSize(collision_box->x2 - collision_box->x1, collision_box->y2 - collision_box->y1);
    view_->SetZ(1);
        
    collidable_ = collidable;
}


DisplayableObject* DisplayableObject::WithHp(double max_hp) {
    hp_bar_ = new HpBar(max_hp, this);
    return this;
}


DisplayableObject* DisplayableObject::WithZ(int z) {
    view_->SetZ(z);
    return this;
}


CollisionBox* DisplayableObject::GetCollisionBox() const {
    return collision_box_;
}

void DisplayableObject::Tick(double dt) {}

bool DisplayableObject::Collidable(Player* p) {
    return collidable_;
}

void DisplayableObject::Damage(double dmg) {
    if (hp_bar_ != 0) {
        hp_bar_->Change(-dmg);
        std::cerr << "boom";
    }
}

double DisplayableObject::GetX() const {
    return collision_box_->x1;
}

double DisplayableObject::GetY() const {
    return collision_box_->y1;
}
