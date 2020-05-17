#include "mouse_input.h"

#include "component/mouse.h"
#include "component/transform.h"
#include "component/state/window.h"

#include <SFML/Graphics.hpp>

#include <iostream>


namespace systems {

MouseInput::MouseInput(SystemManager* manager)
        : System(manager, "MouseInput") {
    InitRequiredComponents();
    InitUsedState();
}

void MouseInput::InitRequiredComponents() {
    AddRequiredComponent<component::Mouse>();
}

void MouseInput::InitUsedState() {
    AddUsedState<component::Window>();
}

void MouseInput::Tick(double dt) {
    auto window = GetState<component::Window>()->GetWindow();
    int width = window->getSize().x;
    int height = window->getSize().y;

    for (auto entity: Entities()) {
        auto mouse_position = sf::Mouse::getPosition(*window);
        if (0 <= mouse_position.x && mouse_position.x < width
                && 0 <= mouse_position.y && mouse_position.y < height) {
            if (!entity->HasComponent<component::Transform>()) {
                system_manager_->AddComponent(
                    entity, new component::Transform());
            }
            auto transform = entity->GetComponent<component::Transform>();
            transform->SetPosition(
                mouse_position.x * 1.0 / width,
                mouse_position.y * 1.0 / height);
        }
        else {
            if (entity->HasComponent<component::Transform>()) {
                system_manager_->RemoveComponent<component::Transform>(entity);
            }
        }
    }
}

}
