#include "collision_detection.h"

#include "component/collision.h"
#include "component/collision_rect.h"
#include "component/movement.h"
#include "component/transform.h"
#include "entity.h"
#include "system_manager.h"


namespace systems {

CollisionDetection::CollisionDetection(SystemManager* manager) 
        : System(manager, "CollisionDetection") {
    InitRequiredComponents();
    InitUsedState();
}


void CollisionDetection::InitRequiredComponents() {
    AddRequiredComponent<component::CollisionRect>();
    AddRequiredComponent<component::Transform>();
}

void CollisionDetection::InitUsedState() {}


void CollisionDetection::Tick(double dt) {
    for (auto entity1: Entities()) {
        if (entity1->HasComponent<component::Collision>()) {
            entity1->RemoveComponent<component::Collision>();
            system_manager_->ComponentRemoved<component::Collision>(entity1);
        }
        component::Collision* collision = 0;
        for (auto entity2: Entities()) {
            if (entity1 == entity2) {
                continue;
            }
            
            auto transform1 = GetComponent<component::Transform>(entity1);
            auto collision_rect1
                = GetComponent<component::CollisionRect>(entity1)
                    ->Move(transform1->GetX(), transform1->GetY());

            if (entity1->HasComponent<component::Movement>()) {
                auto movement = entity1->GetComponent<component::Movement>();
                collision_rect1 = 
                    collision_rect1.Move(movement->GetDx(), movement->GetDy());
            }

            auto transform2 = GetComponent<component::Transform>(entity2);
            auto collision_rect2
                = GetComponent<component::CollisionRect>(entity2)
                    ->Move(transform2->GetX(), transform2->GetY());
            if (entity2->HasComponent<component::Movement>()) {
                auto movement = entity2->GetComponent<component::Movement>();
                collision_rect2 = 
                    collision_rect2.Move(movement->GetDx(), movement->GetDy());
            }


            if (collision_rect1.Intersects(collision_rect2)) {
                std::cerr << "found collision between [" << entity1->Name() 
                    << "] and [" << entity2->Name() << "]" << std::endl;
                if (collision == 0) {
                    collision = new component::Collision(entity2);
                    entity1->AddComponent(collision);
                    system_manager_->ComponentAdded<component::Collision>(entity1);
                }
                else {
                    collision->AddEntity(entity2);
                }
            }
        }
    }
}


}
