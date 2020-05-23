#include "rectangle_pre_render.h"

#include "component/parent_entity.h"
#include "component/rectangle.h"
#include "component/transform.h"
#include "component/state/window.h"
#include "drawable/rectangle_drawable.h"
#include "entity.h"
#include "render_vector.h"
#include "textures.h"
#include "type.h"

#include <SFML/Graphics.hpp>

#include <iostream>


namespace systems {

const Aspect RectanglePreRender::rectangle_aspect_
        = Aspect::CreateAspect<component::Rectangle, component::Transform>();

RectanglePreRender::RectanglePreRender(SystemManager* manager)
        : System(manager, "RectanglePreRender") {
    InitUsedState();
    manager->RegisterAspect(rectangle_aspect_);
}

void RectanglePreRender::InitUsedState() {
    AddUsedState<component::Window>();
    AddUsedState<component::RenderVector>();
}

void RectanglePreRender::Tick(double dt) {
    auto window = GetState<component::Window>()->GetWindow();
    auto render_vector = GetState<component::RenderVector>();

    int width = window->getSize().x;
    int height = window->getSize().y;

    auto entities = system_manager_->GetAspectEntities(rectangle_aspect_);
    
    for (auto entity: entities) {
        auto rectangle = GetComponent<component::Rectangle>(entity);
        auto transform = GetComponent<component::Transform>(entity);
        
        double thickness = rectangle->GetThickness();

        sf::Color color = rectangle->GetColor();

        auto copy_transform = new component::Transform();
        copy_transform->SetPosition(transform->GetX(),
                                    transform->GetY());

        if (entity->HasComponent<component::ParentEntity>()) {
            auto parent_transform 
                = entity
                    ->GetComponent<component::ParentEntity>()
                    ->GetParent()
                    ->GetComponent<component::Transform>();
            copy_transform->SetPosition(
                transform->GetX() + parent_transform->GetX(),
                transform->GetY() + parent_transform->GetY());
        }
        
        sf::RectangleShape* rectangle_shape = new sf::RectangleShape();
        rectangle_shape->setPosition(
            copy_transform->GetX() * width, 
            copy_transform->GetY() * height);



        auto rectangle_size = rectangle->GetSize();



        rectangle_shape->setSize(
            sf::Vector2f(rectangle_size.first * width, rectangle_size.second * height));
        rectangle_shape->setOutlineThickness(thickness * width);
        rectangle_shape->setFillColor(sf::Color::Transparent);
        rectangle_shape->setOutlineColor(color);
        render_vector->push_back({rectangle->GetLayer(), new RectangleDrawable(rectangle_shape)});
    }
}

}
