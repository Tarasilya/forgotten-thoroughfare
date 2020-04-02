#pragma once

#include "objects/passive_object.h"

class HpBar;


class PunchingBag : public PassiveObject {
private:   
    double x_;
    double y_;
    CollisionBox* collision_box_;    
    HpBar* hp_bar_;

public:
    PunchingBag();
    CollisionBox* GetCollisionBox() const override;
    double GetX() const;
    double GetY() const;
    bool Collidable(Player* player) override;
    void Tick(double dt) override;
};
