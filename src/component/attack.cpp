#include "attack.h"

#include <cassert>


namespace component {

Attack::Attack(Entity* entity, double radius, double passed)
        : entity_(entity), radius_(radius), time_(passed) {}

void Attack::AddTime(double dt) {
    time_ += dt;
}

Entity* Attack::GetEntity() {
    return entity_;
}

double Attack::GetRadius() {
    return radius_;
}

double Attack::GetActiveTime() {
    assert(GetState() == ACTIVE);
    return time_ - ACTIVE_T;
}

State Attack::GetState() {
    if (time_ < STARTUP_T) {
        return STARTUP;
    }
    if (time_ < STARTUP_T + ACTIVE_T) {
        return ACTIVE;
    }
    if (time_ < STARTUP_T + ACTIVE_T + RECOVERY_T) {
        return RECOVERY;
    }

    return FINISHED;
}

}
