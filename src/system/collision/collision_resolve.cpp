#include "collision_resolve.h"
#include "component/collision.h"
#include "component/collision_rect.h"
#include "component/movement.h"
#include "component/transform.h"
#include "component/unpassable.h"
#include "entity.h"

#include <cmath>


namespace systems {

const Aspect CollisionResolve::collision_aspect_
        = Aspect::CreateAspect<component::Collision, 
            component::CollisionRect,
            component::Movement,
            component::Transform,
            component::Unpassable>();

CollisionResolve::CollisionResolve(SystemManager* manager) 
        : System(manager, "CollisionResolve") {
    system_manager_->RegisterAspect(collision_aspect_);
    InitUsedState();
}

void CollisionResolve::InitUsedState() {}

const double EPS = 1e-9;

void CollisionResolve::Tick(double dt) {
    std::vector<Entity*> removed;
    auto entities = system_manager_->GetAspectEntities(collision_aspect_);
    for (auto entity: entities) {
        for (auto entity2: GetComponent<component::Collision>(entity)->GetEntities()) {
            if (!entity2->HasComponent<component::Unpassable>()) {
                continue;
            }
            auto transform = GetComponent<component::Transform>(entity);
            auto movement = GetComponent<component::Movement>(entity);
            auto collision = GetComponent<component::CollisionRect>(entity)
                ->Move(transform->GetX(), transform->GetY())
                .Move(movement->GetDx(), movement->GetDy());

            auto transform2 = entity2->GetComponent<component::Transform>();
            auto collision2 = entity2->GetComponent<component::CollisionRect>()
                ->Move(transform2->GetX(), transform2->GetY());

            double x_correction = 0;
            if (abs(movement->GetDx()) > EPS) {
                if (collision.x1 < collision2.x2 && collision2.x1 < collision.x2) {
                    if (movement->GetDx() > 0) {
                        x_correction = collision2.x1 - collision.x2;
                    }
                    else {
                        x_correction = collision2.x2 - collision.x1;
                    }
                }
            }

            double y_correction = 0;
            if (abs(movement->GetDy()) > EPS) {        
                if (collision.y1 < collision2.y2 && collision2.y1 < collision.y2) {
                    if (movement->GetDy() > 0) {
                        y_correction = collision2.y1 - collision.y2;
                    }
                    else {
                        y_correction = collision2.y2 - collision.y1;
                    }
                }
            }

            if (abs(movement->GetDx()) + EPS > abs(x_correction)) {
                movement->SetDx(movement->GetDx() + x_correction);
                if (collision.Move(x_correction, 0).Intersects(collision2)) {
                    movement->SetDy(movement->GetDy() + y_correction);
                }
            }
            else {
                movement->SetDy(movement->GetDy() + y_correction);
                if (collision.Move(0, y_correction).Intersects(collision2)) {
                    movement->SetDx(movement->GetDx() + x_correction);
                }
            }
        }
    }
}


}
