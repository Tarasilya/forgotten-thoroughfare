#pragma once

#include "objects/damageable.h"
#include "objects/passive_object.h"
#include "views/position.h"

class HpBar;
class RectCollisionBox;
class TextureView;

class DisplayableObject : public PassiveObject, public Position, public Damageable {
private:
    TextureView* view_;
    HpBar* hp_bar_ = 0;
    RectCollisionBox* collision_box_;
    bool collidable_;
public:
    DisplayableObject(const std::string& texture_path, bool collidable, RectCollisionBox* collision_box);
    DisplayableObject* WithHp(double max_hp);
    DisplayableObject* WithZ(int z);

    CollisionBox* GetCollisionBox() const override;
    void Tick(double dt) override;
    bool Collidable(Player* p) override;

    double GetX() const override;
    double GetY() const override;

    bool Damage(double dmg) override;
};
