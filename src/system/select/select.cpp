#include "select.h"

#include "component/collision.h"
#include "component/mouse.h"
#include "component/rectangle.h"
#include "component/selectable.h"
#include "component/selected.h"
#include "component/state/map.h"
#include "system/collision/collision_detection.h"


namespace systems {

const Aspect Select::mouse_aspect_
        = Aspect::CreateAspect<component::Mouse,
            component::Collision>();

Select::Select(SystemManager* manager)
        : System(manager, "Select") {
    system_manager_->RegisterAspect(mouse_aspect_);
    InitUsedState();
}

void Select::InitUsedState() {
}

void Select::Tick(double dt) {
    auto mice = system_manager_->GetAspectEntities(mouse_aspect_);
    for (auto mouse_entity: mice) {
        auto mouse = mouse_entity->GetComponent<component::Mouse>();
        if (mouse->LeftState().previous || ! mouse->LeftState().current) {
            continue;
        }
        auto collided = mouse_entity->GetComponent<component::Collision>()->GetEntities();
        for (auto entity: collided) {
            if (!entity->HasComponent<component::Selectable>()) {
                continue;
            }
            if (entity->HasComponent<component::CollisionRect>()) {
                std::cerr << "clicked on: ";
                CollisionDetection::GetMovedRect(entity).Print();
            }
            ToggleSelect(entity);
        }
    }
}

void Select::ToggleSelect(Entity* entity) {
    if (entity->HasComponent<component::Selected>()) {
        system_manager_
            ->RemoveComponent<component::Rectangle>(entity);
        system_manager_
            ->RemoveComponent<component::Selected>(entity);
    }
    else {
        system_manager_
            ->AddComponent(entity, 
                new component::Rectangle(
                    component::TILE_SIZE, 
                    component::TILE_SIZE, 
                    sf::Color::Transparent,
                    5,
                    0.01,
                    sf::Color::White));
        system_manager_
            ->AddComponent(entity, new component::Selected());
    }
}

}
