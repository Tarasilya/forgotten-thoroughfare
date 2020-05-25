#pragma once

#include "system/system.h"


class Entity;
namespace component{
    class MovementOrder;
}

namespace systems {

class SystemManager;

class OrderUnitMovement: public System {
private:
    static const Aspect selected_aspect_;

    component::MovementOrder* MakeMovementOrder(Entity* from, Entity* to);

protected:
    void InitUsedState() override;

public:
    OrderUnitMovement(SystemManager* manager);

    void Tick(double dt) override;
};

}
