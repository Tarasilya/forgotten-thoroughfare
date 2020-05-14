#include "camera_apply.h"

#include "camera.h"
#include "component/state/window.h"
#include "system/render/drawable/drawable.h"
#include "system/render/render_vector.h"

#include <SFML/Graphics.hpp>


namespace systems {

CameraApply::CameraApply(SystemManager* manager)
        : Entityless(manager, "CameraApply") {
    InitUsedState();
}

void CameraApply::InitUsedState() {
    AddUsedState<component::Camera>();
    AddUsedState<component::Window>();
    AddUsedState<component::RenderVector>();
}

void CameraApply::Tick(double dt) {
    auto camera = GetState<component::Camera>();
    auto render_queue = GetState<component::RenderVector>();
    auto window_size = GetState<component::Window>()->GetWindow()->getSize();


    for (auto drawable: *render_queue) {
        drawable.second->Move(-camera->x1 * window_size.x, 
            -camera->y1 * window_size.y);
    }
}

}
