#include "select.h"

#include "component/collision.h"
#include "component/mouse.h"
#include "component/rectangle.h"
#include "component/selectable.h"
#include "map.h"


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
            if (entity->HasComponent<component::Rectangle>()) {
                system_manager_
                    ->RemoveComponent<component::Rectangle>(entity);
            }
            else {
                system_manager_
                    ->AddComponent(entity, 
                        new component::Rectangle(sf::Color::White, 
                            TILE_SIZE, TILE_SIZE, 0.01, 5));
            }
        }
    }
}

}
