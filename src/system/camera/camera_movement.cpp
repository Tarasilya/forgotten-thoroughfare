#include "camera_movement.h"

#include "camera.h"
#include "component/collision_rect.h"
#include "component/player.h"
#include "component/transform.h"

#include <cmath>


namespace systems {

CameraMovement::CameraMovement(SystemManager* manager)
        : System(manager, "CameraMovement") {
    InitRequiredComponents();
    InitUsedState();
}


void CameraMovement::InitRequiredComponents() {
    AddRequiredComponent<component::Player>();
    AddRequiredComponent<component::Transform>();
}

void CameraMovement::InitUsedState() {
    AddUsedState<component::Camera>();
}


const double MARGIN = 0.33;

void CameraMovement::Tick(double dt) {
    auto camera = GetState<component::Camera>();
    for (auto entity: Entities()) {
        auto transform = GetComponent<component::Transform>(entity);
        double left = std::max(camera->x1 - (transform->GetX() - MARGIN), 0.);
        double right = std::max((transform->GetX() + MARGIN) - camera->x2, 0.);
        double top = std::max(camera->y1 - (transform->GetY() - MARGIN), 0.);
        double bottom = std::max((transform->GetY() + MARGIN) - camera->y2, 0.);
        *static_cast<component::CollisionRect*>(camera) = camera->Move(right - left, bottom - top);
    }
}

}
