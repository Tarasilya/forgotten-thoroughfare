#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class CollisionResolve: public System {
private:
    static const Aspect collision_aspect_;

protected:
    void InitUsedState() override;

public:
    CollisionResolve(SystemManager* manager);

    void Tick(double dt) override;
};

}
