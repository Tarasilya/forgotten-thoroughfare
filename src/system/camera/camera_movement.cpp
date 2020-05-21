#include "camera_movement.h"

#include "camera.h"
#include "component/collision_rect.h"
#include "component/mouse.h"
#include "component/transform.h"

#include <cmath>


namespace systems {

const Aspect CameraMovement::mouse_aspect_
    = Aspect::CreateAspect<component::Mouse, component::Transform>();

CameraMovement::CameraMovement(SystemManager* manager)
        : System(manager, "CameraMovement") {
    system_manager_->RegisterAspect(mouse_aspect_);
    InitUsedState();
}

void CameraMovement::InitUsedState() {
    AddUsedState<component::Camera>();
}


const double MARGIN = 0.1;
const double CAMERA_SPEED = 0.0003;

void CameraMovement::Tick(double dt) {
    auto camera = GetState<component::Camera>();
    auto entities = system_manager_->GetAspectEntities(mouse_aspect_);
    for (auto entity: entities) {
        auto transform = GetComponent<component::Transform>(entity);
        double x_speed = 0;
        double y_speed = 0;
        if (transform->GetX() < MARGIN) {
            x_speed -= CAMERA_SPEED;
        }
        if (transform->GetX() > 1 - MARGIN) {
            x_speed += CAMERA_SPEED;
        }
        if (transform->GetY() < MARGIN) {
            y_speed -= CAMERA_SPEED;
        }
        if (transform->GetY() > 1 - MARGIN) {
            y_speed += CAMERA_SPEED;
        }
        *static_cast<component::CollisionRect*>(camera) 
            = camera->Move(x_speed * dt, y_speed * dt);
    }
}

}
