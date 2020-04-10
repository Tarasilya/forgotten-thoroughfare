#include "punching_bag.h"
#include "objects/player/hp_bar.h"
#include "painter/painter.h"
#include "views/texture_view.h"

const double WIDTH = 0.05;
const double HEIGHT = 0.1;
const double MAX_HP = 100;


PunchingBag::PunchingBag() {
    hp_bar_ = new HpBar(MAX_HP, this);
    x_ = 0;
    y_ = -0.4;
    collision_box_ = new RectCollisionBox(x_, y_, x_ + WIDTH, y_ + HEIGHT);

    View* view = (new TextureView("pics/punch_bag.png", this))->SetSize(WIDTH, HEIGHT)->SetZ(1);
    Painter::GetPainter()->AddView(view);
}

void PunchingBag::Damage(double dmg) {
    hp_bar_->Change(-dmg);
}

CollisionBox* PunchingBag::GetCollisionBox() const {
    return collision_box_;
}

double PunchingBag::GetX() {
    return x_;
}

double PunchingBag::GetY() {
    return y_;
}

void PunchingBag::Tick(double dt) {}

bool PunchingBag::Collidable(Player* player) {
    return false;
}