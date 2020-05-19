#include "sprite_pre_render.h"

#include "component/parent_entity.h"
#include "component/sprite.h"
#include "component/transform.h"
#include "component/state/window.h"
#include "drawable/sprite_drawable.h"
#include "entity.h"
#include "render_vector.h"
#include "textures.h"
#include "type.h"

#include <SFML/Graphics.hpp>

#include <iostream>


namespace systems {

SpritePreRender::SpritePreRender(SystemManager* manager)
        : System(manager, "SpritePreRender") {
    InitUsedState();

    manager->RegisterAspect(
        Aspect::CreateAspect<component::Sprite, component::Transform>());
}

void SpritePreRender::InitUsedState() {
    AddUsedState<component::Window>();
    AddUsedState<component::RenderVector>();
}

void SpritePreRender::Tick(double dt) {
    auto window = GetState<component::Window>()->GetWindow();
    auto render_vector = GetState<component::RenderVector>();

    int width = window->getSize().x;
    int height = window->getSize().y;

    auto entities = system_manager_->GetAspectEntities
    for (auto entity: Entities()) {
        auto sprite_drawable = GetComponent<component::Sprite>(entity);
        auto transform = GetComponent<component::Transform>(entity);
        auto file = sprite_drawable->GetDrawable();

        if (entity->HasComponent<component::ParentEntity>()) {
            auto parent_transform 
                = entity
                    ->GetComponent<component::ParentEntity>()
                    ->GetParent()
                    ->GetComponent<component::Transform>();
            transform->SetPosition(
                transform->GetX() + parent_transform->GetX(),
                transform->GetY() + parent_transform->GetY());
        }
        
        sf::Sprite* sprite = new sf::Sprite();
        auto texture = Textures::Get(file);
        sprite->setTexture(*texture);
        sprite->setPosition(
            transform->GetX() * width, 
            transform->GetY() * height);
        sprite->setRotation(transform->GetRotation());


        auto sprite_size = sprite_drawable->GetSize();
        double x_scale = sprite_size.first * window->getSize().x 
            * transform->GetScaleX() / texture->getSize().x;
        double y_scale = sprite_size.second * window->getSize().y
            * transform->GetScaleY() / texture->getSize().y;

        sprite->setScale(x_scale, y_scale);
        render_vector->push_back({sprite_drawable->GetLayer(), new SpriteDrawable(sprite)});
    }
}

}
