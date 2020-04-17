#include "attack_view.h"

#include "objects/player.h"
#include "objects/player/attack.h"
#include "painter/painter.h"

#include <iostream>

const Color STARTUP_COLOR = Color(100, 100, 100);
const Color ACTIVE_COLOR = Color(0, 0, 0);

AttackView::AttackView(const Attack* attack, const Position* player_position, double player_size)
        : TextureView("pics/supercool_sword.png", this), attack_(attack), player_position_(player_position), player_size_(player_size) {
    SetVisibility(this);
    SetSize(SWORD_WIDTH, SWORD_HEIGHT);
    //SetCollisionVisibility(true);
    SetZ(100);
}

void AttackView::Draw(Painter* painter) {
    State state = attack_->GetState();
    if (state == IDLE || state == RECOVERY) {
        return;
    }

    double time_passed = attack_->GetActiveTime();
    double angle = -(1 - time_passed / ACTIVE_T) * TOTAL_ANGLE;
    if (attack_->GetDirection() < 0) {
        angle = -M_PI - angle;
    }

    sprite_->setRotation(angle * 360 / (2 * M_PI));

    x_ = player_position_->GetX() + player_size_ / 2;
    y_ = player_position_->GetY() + player_size_ / 2;
    x_ += std::cos(angle) * player_size_ / 2;
    y_ += std::sin(angle) * player_size_ / 2;

    TextureView::Draw(painter);    
}

CollisionBox* AttackView::GetCollisionBox() {
    if (attack_->GetState() == ACTIVE) {
        Painter* painter = Painter::GetPainter();
        auto rect = sprite_->getGlobalBounds();
        double x1 = rect.left / painter->Width();
        double y1 = rect.top / painter->Height();
        double x2 = (rect.left + rect.width) / painter->Width();
        double y2 = (rect.top + rect.height) / painter->Height();
        return new RectCollisionBox(x1, y1, x2, y2);
    }
    else return new NullCollisionBox();
}

bool AttackView::GetVisibility() {
    State state = attack_->GetState();
    return state == ACTIVE || state == STARTUP;
}

double AttackView::GetX() const {
    return x_;
}

double AttackView::GetY() const {
    return y_;
}