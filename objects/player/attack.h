#pragma once

#include "objects/passive_object.h"

class AttackView;

enum State {IDLE, STARTUP, ACTIVE, RECOVERY};

const double STARTUP_T = 0.3;
const double ACTIVE_T = 0.5;
const double RECOVERY_T = 0;


class Attack : public PassiveObject{
private:
    mutable State state_;
    clock_t start_time_;
    const Player* player_;
    int charges_;

    AttackView* view_;

    void UpdateState() const;
public:
    Attack(const Player* player);
    void Trigger();

    CollisionBox* GetCollisionBox() const override;
    void Tick(double dt) override;
    bool Collidable(Player* p) override;

    State GetState() const;
    double GetActiveTime() const;
    int GetDirection() const;
};
