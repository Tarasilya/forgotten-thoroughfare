#include "order_unit_movement.h"

#include "component/collision.h"
#include "component/collision_rect.h"
#include "component/movement_order.h"
#include "component/rectangle.h"
#include "component/selected.h"
#include "component/state/map.h"
#include "component/transform.h"
#include "component/unit.h"


namespace systems {

const Aspect OrderUnitMovement::selected_aspect_
        = Aspect::CreateAspect<component::Selected>();

OrderUnitMovement::OrderUnitMovement(SystemManager* manager)
        : System(manager, "OrderUnitMovement") {
    system_manager_->RegisterAspect(selected_aspect_);
    InitUsedState();
}

void OrderUnitMovement::InitUsedState() {
    AddUsedState<component::Map>();
}

void OrderUnitMovement::Tick(double dt) {
    auto selected_set = system_manager_->GetAspectEntities(selected_aspect_);
    std::vector<Entity*> selected = std::vector<Entity*>(
        selected_set.begin(), selected_set.end());
    if (selected.size() != 2) {
        return;
    }
    Entity* from;
    Entity* to;
    if (selected[0]->GetComponent<component::Selected>()->When()
            < selected[1]->GetComponent<component::Selected>()->When()) {
        from = selected[0];
        to = selected[1];
    }
    else {
        from = selected[1];
        to = selected[0];
    }
    for (auto entity: selected) {
        system_manager_->RemoveComponent<component::Selected>(entity);
        system_manager_->RemoveComponent<component::Rectangle>(entity);
    }
    if (!from->HasComponent<component::Collision>()) {
        return;
    }

    auto movement_order = MakeMovementOrder(from, to);
    auto potential_units = from->GetComponent<component::Collision>()->GetEntities();
    for (auto unit: potential_units) {
        if (!unit->HasComponent<component::Unit>()) {
            continue;
        }
        if (unit->HasComponent<component::MovementOrder>()) {
            unit->RemoveComponent<component::MovementOrder>();
        }
        system_manager_->AddComponent(unit, movement_order);
    }
}

component::MovementOrder* OrderUnitMovement::MakeMovementOrder(Entity* from, Entity* to) {
    auto map = GetState<component::Map>();
    auto path = map->GetPath(from, to);
    for (auto tile: path) {
        auto transform = tile->GetComponent<component::Transform>();
        auto rect = tile
            ->GetComponent<component::CollisionRect>()
            ->Move(transform->GetX(), transform->GetY());
    }
    return new component::MovementOrder(path);
}

}
