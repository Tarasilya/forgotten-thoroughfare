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

void ExecuteUnitMovement::Tick(double dt) {
    auto entities = system_manager_->GetAspectEntities(movement_order_aspect_);
    std::vector<Entity*> removed;
    for (auto entity: entities) {
        auto transform = entity->GetComponent<component::Transform>();
        auto order = entity->GetComponent<component::MovementOrder>();
        auto unit_rect = CollisionDetection::GetMovedRect(entity);
        auto tile_rect = CollisionDetection::GetMovedRect(order->Path()[0]);
        if (!unit_rect.Intersects(tile_rect)) {
            order->PopFirst();
        }
        if (order->Size() <= 1) {
            removed.push_back(entity);
            continue;
        }
        auto cur_center = GetCenter(order->Path()[0]);
        auto next_center = GetCenter(order->Path()[1]);
        if (RoughlyEqual(
                cur_center.GetY(),
                next_center.GetY())) {
            if (!RoughlyEqual(next_center.GetY(), transform->GetY())) {
                if (transform->GetY() < next_center.GetY()) {
                    transform->SetY(
                        std::min(transform->GetY() + UNIT_SPEED * dt, next_center.GetY()));
                }
                else {
                    transform->SetY(
                        std::max(transform->GetY() - UNIT_SPEED * dt, next_center.GetY()));   
                }
            }
            else {
                if (transform->GetX() < next_center.GetX()) {
                    transform->SetX(
                        std::min(transform->GetX() + UNIT_SPEED * dt, next_center.GetX()));
                }
                else {
                    transform->SetX(
                        std::max(transform->GetX() - UNIT_SPEED * dt, next_center.GetX()));   
                }
            }
        }
        else if (RoughlyEqual(
                cur_center.GetX(),
                next_center.GetX())) {
            if (!RoughlyEqual(next_center.GetX(), transform->GetX())) {
                if (transform->GetX() < next_center.GetX()) {
                    transform->SetX(
                        std::min(transform->GetX() + UNIT_SPEED * dt, next_center.GetX()));
                }
                else {
                    transform->SetX(
                        std::max(transform->GetX() - UNIT_SPEED * dt, next_center.GetX()));
                }
            }
            else {
                if (transform->GetY() < next_center.GetY()) {
                    transform->SetY(
                        std::min(transform->GetY() + UNIT_SPEED * dt, next_center.GetY()));
                }
                else {
                    transform->SetY(
                        std::max(transform->GetY() - UNIT_SPEED * dt, next_center.GetY()));
                }
            }
        }
        else {
            assert (false && "bro wtf");
        }
    }
    for (auto entity: removed) {
        system_manager_->RemoveComponent<component::MovementOrder>(entity);
    }
}

component::Transform ExecuteUnitMovement::GetCenter(Entity* entity) {
    auto rect = CollisionDetection::GetMovedRect(entity);
    return component::Transform(
        rect.x1 + component::TILE_SIZE / 2,
        rect.y1 + component::TILE_SIZE / 2);
}

const double EPS = 1e-9;

bool ExecuteUnitMovement::RoughlyEqual(double x, double y) {
    return std::abs(x-y) < EPS;
}

}
