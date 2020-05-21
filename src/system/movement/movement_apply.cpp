#include "movement_apply.h"

#include "component/movement.h"
#include "component/player.h"
#include "component/transform.h"
#include "component/state/input.h"


namespace systems {

const Aspect MovementApply::movement_aspect_
        = Aspect::CreateAspect<component::Movement,
            component::Transform>();

MovementApply::MovementApply(SystemManager* manager)
        : System(manager, "MovementApply") {
    system_manager_->RegisterAspect(movement_aspect_);
    InitUsedState();
}

void MovementApply::InitUsedState() {
}

void MovementApply::Tick(double dt) {
    std::vector<Entity*> removed;

    auto entities = system_manager_->GetAspectEntities(movement_aspect_);
    for (auto entity: entities) {
        auto transform = GetComponent<component::Transform>(entity);
        auto movement = GetComponent<component::Movement>(entity);
        transform->SetX(transform->GetX() + movement->GetDx());
        transform->SetY(transform->GetY() + movement->GetDy()); 

        removed.push_back(entity);       
    }

    for (auto entity: removed) {
        system_manager_->RemoveComponent<component::Movement>(entity);
    }
}

}
