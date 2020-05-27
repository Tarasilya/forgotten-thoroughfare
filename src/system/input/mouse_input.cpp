#include "mouse_input.h"

#include "component/transform.h"
#include "component/state/window.h"
#include "system/camera/camera.h"

#include <SFML/Graphics.hpp>

#include <iostream>


namespace systems {

const Aspect MouseInput::mouse_aspect_
    = Aspect::CreateAspect<component::Mouse>();

MouseInput::MouseInput(SystemManager* manager)
        : System(manager, "MouseInput") {
    system_manager_->RegisterAspect(mouse_aspect_);
    InitUsedState();
}

void MouseInput::InitUsedState() {
    AddUsedState<component::Camera>();
    AddUsedState<component::Window>();
}

void MouseInput::Tick(double dt) {
    auto window = GetState<component::Window>()->GetWindow();
    int width = window->getSize().x;
    int height = window->getSize().y;
    auto camera = GetState<component::Camera>();

    auto entities = system_manager_->GetAspectEntities(mouse_aspect_);
    for (auto entity: entities) {
        auto mouse_position = sf::Mouse::getPosition(*window);
        if (0 <= mouse_position.x && mouse_position.x < width
                && 0 <= mouse_position.y && mouse_position.y < height) {
            if (!entity->HasComponent<component::Transform>()) {
                system_manager_->AddComponent(
                    entity, new component::Transform());
            }
            auto transform = entity->GetComponent<component::Transform>();
            transform->SetPosition(
                mouse_position.x * 1.0 / width + camera->x1,
                mouse_position.y * 1.0 / height + camera->y1);
            // std::cerr << mouse_position.x * 1.0 / width + camera->x1
            //     << " " << mouse_position.y * 1.0 / height + camera->y1 << std::endl;
        }
        else {
            if (entity->HasComponent<component::Transform>()) {
                system_manager_->RemoveComponent<component::Transform>(entity);
            }
        }

        auto mouse = entity->GetComponent<component::Mouse>();
        mouse->UpdateLeft(sf::Mouse::isButtonPressed(sf::Mouse::Left));
    }
}

}
