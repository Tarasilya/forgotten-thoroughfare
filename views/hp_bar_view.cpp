#include "hp_bar_view.h"

#include "collisions/rect_collision_box.h"
#include "painter/painter.h"
#include "objects/game_object.h"
#include "objects/player/hp_bar.h"

#include <iostream>

const double BAR_HEIGHT = 0.015;

HpBarView::HpBarView(const HpBar* hp_bar, const GameObject* object): hp_bar_(hp_bar), object_(object) {
    z_ = 5;
}

void HpBarView::Draw(Painter* painter) {
    RectCollisionBox* box = (RectCollisionBox*) object_->GetCollisionBox();


    double percentage = hp_bar_->GetCurrent() / hp_bar_->GetMax();

    double green_size = (box->x2 - box->x1) * percentage;

    double y1 = box->y1 - BAR_HEIGHT;
    double y2 = box->y1;

    Rectangle green = {box->x1, y1, box->x1 + green_size, y2, Color(0, 255, 0)};
    Rectangle red = {box->x1 + green_size, y1, box->x2, y2, Color(255, 0, 0)};

    painter->Draw(red);
    painter->Draw(green);
}
