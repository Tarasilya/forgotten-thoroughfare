#include "collision_detection.h"

#include "component/collision.h"
#include "component/collision_rect.h"
#include "component/movement.h"
#include "component/transform.h"
#include "entity.h"


namespace systems {

const Aspect CollisionDetection::collision_aspect_
        = Aspect::CreateAspect<component::CollisionRect, component::Transform>();

CollisionDetection::CollisionDetection(SystemManager* manager) 
        : System(manager, "CollisionDetection") {
    system_manager_->RegisterAspect(collision_aspect_);
    InitUsedState();
}


void CollisionDetection::InitUsedState() {}


void CollisionDetection::Tick(double dt) {
    auto entities = system_manager_->GetAspectEntities(collision_aspect_);
    for (auto entity1: entities) {
        if (!entity1->HasComponent<component::Movement>()) {
            continue;
        }
        if (entity1->HasComponent<component::Collision>()) {
            system_manager_->RemoveComponent<component::Collision>(entity1);
        }
        component::Collision* collision = 0;
        for (auto entity2: entities) {
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
                    system_manager_->AddComponent(entity1, collision);
                }
                else {
                    collision->AddEntity(entity2);
                }
            }
        }
    }
}


}
