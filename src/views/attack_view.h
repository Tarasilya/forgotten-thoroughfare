#pragma once

#include "views/texture_view.h"
#include "views/visible.h"
#include "views/position.h"

#include <cmath>

class Attack;
class CollisionBox;

const double TOTAL_ANGLE = M_PI / 2 * 1.5;
const double SWORD_WIDTH = 0.1;
const double SWORD_HEIGHT = 0.03;

class AttackView : public TextureView, public Position, public Visible {
private:
    const Attack* attack_;
    const Position* player_position_;
    double player_size_;

    double x_;
    double y_;
public:
    AttackView(const Attack* attack, const Position* player_position, double player_size);
    void Draw(Painter* painter) override;

    CollisionBox* GetCollisionBox();

    bool GetVisibility() override;

    double GetX() const override;
    double GetY() const override;
};
