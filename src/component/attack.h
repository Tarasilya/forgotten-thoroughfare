#pragma once

#include "component.h"

#include <cmath>


class Entity;

namespace component {

const double STARTUP_T = 100;
const double ACTIVE_T = 600;
const double RECOVERY_T = 100;

const double TOTAL_ANGLE = M_PI / 2 * 1.5;

enum State {
    STARTUP, ACTIVE, RECOVERY, FINISHED
};


class Attack: public Component {
private:
    Entity* entity_;
    double radius_;
    double time_;

public:
    Attack(Entity* entity, double radius, double passed = 0);

    void AddTime(double dt);
    Entity* GetEntity();
    double GetRadius();
    double GetActiveTime();
    State GetState();
};

}
