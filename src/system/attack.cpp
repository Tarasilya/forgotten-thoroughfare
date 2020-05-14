#include "attack.h"

#include "component/attack.h"
#include "component/transform.h"


namespace systems {



Attack::Attack(SystemManager* manager)
        : System(manager, "Attack") {
    InitRequiredComponents();
    InitUsedState();
}


void Attack::InitRequiredComponents() {
    AddRequiredComponent<component::Attack>();
}

void Attack::InitUsedState() {
}

void Attack::Tick(double dt) {
    std::vector<Entity*> removed;
    for (auto entity: Entities()) {
        auto attack = GetComponent<component::Attack>(entity);
        attack->AddTime(dt);
        auto state = attack->GetState();

        if (state == component::RECOVERY || state == component::FINISHED) {
            removed.push_back(entity);
            system_manager_->RemoveEntity(attack->GetEntity());
        }
        else {
            double time_passed 
                = (state == component::ACTIVE) ? attack->GetActiveTime() : 0;
            double angle 
                = -(1 - time_passed / component::ACTIVE_T) * component::TOTAL_ANGLE;
            // if (attack_->GetDirection() < 0) {
            //     angle = -M_PI - angle;
            // }

            auto attack_transform
                = attack->GetEntity()->GetComponent<component::Transform>();

            double x = std::cos(angle) * attack->GetRadius();
            double y = std::sin(angle) * attack->GetRadius();

            attack_transform->SetPosition(x, y);
            attack_transform->SetRotation(angle * 360 / (2 * M_PI));
        }
    }

    for (auto entity: removed) {
        system_manager_->RemoveComponent<component::Attack>(entity);
    }
}

}
