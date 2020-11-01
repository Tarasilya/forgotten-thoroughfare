#include "execute_unit_movement.h"

#include "component/collision_rect.h"
#include "component/movement_order.h"
#include "component/state/map.h"
#include "system/collision/collision_detection.h"

#include <cmath>


namespace systems {

const Aspect ExecuteUnitMovement::movement_order_aspect_
        = Aspect::CreateAspect<
            component::MovementOrder,
            component::CollisionRect,
            component::Transform>();

ExecuteUnitMovement::ExecuteUnitMovement(SystemManager* manager)
        : System(manager, "ExecuteUnitMovement") {
    system_manager_->RegisterAspect(movement_order_aspect_);
    InitUsedState();
}

void ExecuteUnitMovement::InitUsedState() {}

const double UNIT_SPEED = 0.0001;
const double EPS = 1e-9;

void ExecuteUnitMovement::Tick(double dt) {
    auto entities = system_manager_->GetAspectEntities(movement_order_aspect_);
    std::vector<Entity*> removed;
    for (auto entity: entities) {
        auto transform = entity->GetComponent<component::Transform>();
        auto order = entity->GetComponent<component::MovementOrder>();
        auto unit_rect = CollisionDetection::GetMovedRect(entity);
        auto tile_rect = CollisionDetection::GetMovedRect(order->Path()[0]);
        auto cur_center = GetCenter(tile_rect);
        auto unit_center = GetCenter(unit_rect);
        if (!unit_rect.Intersects(tile_rect)) {
            order->PopFirst();
        }
        if (order->Size() <= 1) {
            if (Manhattan(unit_center, cur_center) > EPS) {
                MoveTowards(transform, UNIT_SPEED * dt, unit_center, cur_center);
            }
            else {
                removed.push_back(entity);
            }
            continue;
        }
        auto next_tile_rect = CollisionDetection::GetMovedRect(order->Path()[1]);
        auto next_center = GetCenter(next_tile_rect);
        if (Manhattan(cur_center, next_center) + EPS < Manhattan(unit_center, next_center)) {
            MoveTowards(transform, UNIT_SPEED * dt, unit_center, cur_center);
        }
        else {
            MoveTowards(transform, UNIT_SPEED * dt, unit_center, next_center);    
        }
    }
    for (auto entity: removed) {
        system_manager_->RemoveComponent<component::MovementOrder>(entity);
    }
}

void ExecuteUnitMovement::MoveTowards(component::Transform* unit_transform,
        double speed,
        component::Transform unit_center,
        component::Transform target_center) {
    if (RoughlyEqual(unit_center.GetX(), target_center.GetX())) {
        AdjustY(unit_transform, speed, unit_center.GetY(), target_center.GetY());
    }
    else {
        AdjustX(unit_transform, speed, unit_center.GetX(), target_center.GetX());
    }
}

void ExecuteUnitMovement::AdjustX(component::Transform* unit_transform,
        double speed, double cur_x, double target_x) {
    double movemant_cap = std::abs(cur_x - target_x);
    double delta = cur_x < target_x ? std::min(speed, movemant_cap) : -std::min(speed, movemant_cap);
    unit_transform->SetX(unit_transform->GetX() + delta);
}

void ExecuteUnitMovement::AdjustY(component::Transform* unit_transform,
        double speed, double cur_y, double target_y) {
    double movemant_cap = std::abs(cur_y - target_y);
    double delta = cur_y < target_y ? std::min(speed, movemant_cap) : -std::min(speed, movemant_cap);
    unit_transform->SetY(unit_transform->GetY() + delta);
}

double ExecuteUnitMovement::Manhattan(component::Transform a, component::Transform b) {
    return std::abs(a.GetX() - b.GetX()) + std::abs(a.GetY() - b.GetY());
}

component::Transform ExecuteUnitMovement::GetCenter(component::CollisionRect rect) {
    return component::Transform(
        (rect.x1 + rect.x2) / 2,
        (rect.y1 + rect.y2) / 2);
}

bool ExecuteUnitMovement::RoughlyEqual(double x, double y) {
    return std::abs(x-y) < EPS;
}

}
