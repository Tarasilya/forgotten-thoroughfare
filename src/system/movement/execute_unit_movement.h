#pragma once

#include "component/collision_rect.h"
#include "component/transform.h"
#include "system/system.h"



namespace systems {

class SystemManager;

class ExecuteUnitMovement: public System {
private:
    static const Aspect movement_order_aspect_;

    bool RoughlyEqual(double x, double y);
    component::Transform GetCenter(component::CollisionRect rect);
    void AdjustX(component::Transform* unit_transform,
        double speed, double cur_x, double target_x);
    void AdjustY(component::Transform* unit_transform,
        double speed, double cur_y, double target_y);
    double Manhattan(component::Transform a, component::Transform b);
    void MoveTowards(component::Transform* unit_transform,
        double speed,
        component::Transform unit_center,
        component::Transform target_center);

protected:
    void InitUsedState() override;

public:
    ExecuteUnitMovement(SystemManager* manager);

    void Tick(double dt) override;
};

}
