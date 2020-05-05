#include "movement_apply.h"

#include "component/movement.h"
#include "component/player.h"
#include "component/transform.h"
#include "component/state/input.h"


namespace systems {

MovementApply::MovementApply(SystemManager* manager)
        : System(manager, "MovementApply") {
    InitRequiredComponents();
    InitUsedState();
}


void MovementApply::InitRequiredComponents() {
    AddRequiredComponent<component::Transform>();
    AddRequiredComponent<component::Movement>();
}

void MovementApply::InitUsedState() {
}

void MovementApply::Tick(double dt) {
    std::vector<Entity*> removed;
    for (auto entity: Entities()) {
        auto transform = GetComponent<component::Transform>(entity);
        auto movement = GetComponent<component::Movement>(entity);
        transform->SetX(transform->GetX() + movement->GetDx());
        transform->SetY(transform->GetY() + movement->GetDy()); 

        removed.push_back(entity);       
    }

    for (auto entity: removed) {
        entity->RemoveComponent<component::Movement>();
        system_manager_->ComponentRemoved<component::Movement>(entity);
    }
}

}
