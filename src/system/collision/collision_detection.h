#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class CollisionDetection: public System {
private:
    static const Aspect collision_aspect_;
protected:
    void InitUsedState() override;

public:
    CollisionDetection(SystemManager* manager);

    void Tick(double dt) override;
};

}
