#pragma once

#include "component/transform.h"
#include "system/system.h"



namespace systems {

class SystemManager;

class ExecuteUnitMovement: public System {
private:
    static const Aspect movement_order_aspect_;

    bool RoughlyEqual(double x, double y);
    component::Transform GetCenter(Entity* entity);

protected:
    void InitUsedState() override;

public:
    ExecuteUnitMovement(SystemManager* manager);

    void Tick(double dt) override;
};

}
