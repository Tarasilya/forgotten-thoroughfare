#pragma once

#include "objects/passive_object.h"

enum State {IDLE, STARTUP, ACTIVE, RECOVERY};

class Attack : public PassiveObject{
private:
    mutable State state_;
    clock_t start_time_;
    const Player* player_;
    int charges_;

    void UpdateState() const;
public:
    Attack(const Player* player);
    void Trigger();

    CollisionBox* GetCollisionBox() const override;
    void Tick(double dt) override;
    bool Collidable(Player* p) override;

    State GetState() const;
};
