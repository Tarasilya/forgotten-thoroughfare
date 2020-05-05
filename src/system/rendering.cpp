#include "rendering.h"

#include "component/sprite_drawable.h"
#include "component/transform.h"
#include "component/state/window.h"
#include "entity.h"
#include "textures.h"
#include "type.h"

#include <iostream>


namespace systems {

Rendering::Rendering(SystemManager* manager)
        : System(manager, "Rendering") {
    InitRequiredComponents();
    InitUsedState();

    int size = sf::VideoMode::getDesktopMode().height * 0.9;
    auto window_component = GetState<component::Window>();
    window_component->Init(size, size);
}

void Rendering::InitRequiredComponents() {
    AddRequiredComponent<component::SpriteDrawable>();
    AddRequiredComponent<component::Transform>();
}

void Rendering::InitUsedState() {
    AddUsedState<component::Window>();
}

void Rendering::Tick(double dt) {
    auto window = GetState<component::Window>()->GetWindow();

    int width = window->getSize().x;
    int height = window->getSize().y;

    window->clear({150, 150, 150});
    for (auto entity: Entities()) {
        auto sprite_drawable = GetComponent<component::SpriteDrawable>(entity);
        auto transform = GetComponent<component::Transform>(entity);
        auto file = sprite_drawable->GetDrawable();

        
        sf::Sprite sprite;
        sprite.setTexture(*Textures::Get(file));
        sprite.setPosition(
            transform->GetX() * width, 
            transform->GetY() * height);
        sprite.setRotation(transform->GetRotation());
        sprite.setScale(transform->GetScaleX(), transform->GetScaleY());
        window->draw(sprite);
    }
    window->display();
}

}
