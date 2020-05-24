#include "collision_detection.h"

#include "collision_grid.h"
#include "component/collision.h"
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
    CollisionGrid<20> collision_grid = CollisionGrid<20>(3);
    for (auto entity: entities) {
        collision_grid.Add(entity);
    }


    for (auto entity1: entities) {
        if (entity1->HasComponent<component::Collision>()) {
            system_manager_->RemoveComponent<component::Collision>(entity1);
        }
        component::Collision* collision = 0;
        std::vector<std::vector<Entity*>> potential
            = collision_grid.GetPotentialCollisions(entity1);
        for (auto v: potential) {
            for (auto entity2: v) {
                if (entity1 == entity2) {
                    continue;
                }
                                
                auto collision_rect1 = GetMovedRect(entity1);
                auto collision_rect2 = GetMovedRect(entity2);
                // if (entity1->Name() == "mouse") {
                //     std::cerr << collision_rect1.x1 << " "
                //         << collision_rect1.x2 << " "
                //         << collision_rect1.y1 << " "
                //         << collision_rect1.y2 << ", "
                //         << collision_rect2.x1 << " "
                //         << collision_rect2.x2 << " "
                //         << collision_rect2.y1 << " "
                //         << collision_rect2.y2 << " " << std::endl;
                // }

                if (collision_rect1.Intersects(collision_rect2)) {
                    //std::cerr << "inter!" << std::endl;
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
        // if (entity1->Name() == "mouse") {
        //     std::cerr << "=============" << std::endl;
        // }
    }
}

component::CollisionRect CollisionDetection::GetMovedRect(Entity* entity) {
    auto transform = entity->GetComponent<component::Transform>();
    auto collision_rect
        = entity->GetComponent<component::CollisionRect>()
            ->Move(transform->GetX(), transform->GetY());
    if (entity->HasComponent<component::Movement>()) {
        auto movement = entity->GetComponent<component::Movement>();
        collision_rect = 
            collision_rect.Move(movement->GetDx(), movement->GetDy());
    }
    return collision_rect;
}


}
