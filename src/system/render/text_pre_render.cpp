#include "text_pre_render.h"

#include "component/parent_entity.h"
#include "component/hud.h"
#include "component/state/window.h"
#include "entity.h"
#include "render_vector.h"
#include "drawable/text_drawable.h"

#include <SFML/Graphics.hpp>

#include <iostream>


namespace systems {

const Aspect TextPreRender::text_aspect_
        = Aspect::CreateAspect<component::Text, component::Transform>();

TextPreRender::TextPreRender(SystemManager* manager)
        : System(manager, "TextPreRender") {
    InitUsedState();

    manager->RegisterAspect(text_aspect_);

    if (!font_.loadFromFile("SEASRN__.ttf"))
    {
        std::cerr << "cant load font!!" << std::endl;
    }
}


void TextPreRender::InitUsedState() {
    AddUsedState<component::Window>();
    AddUsedState<component::RenderVector>();
}

void TextPreRender::Tick(double dt) {
    auto window = GetState<component::Window>()->GetWindow();
    auto render_vector = GetState<component::RenderVector>();

    int width = window->getSize().x;
    int height = window->getSize().y;

    auto entities = system_manager_->GetAspectEntities(text_aspect_);
    for (auto entity: entities) {
        auto text = GetComponent<component::Text>(entity)->GetText();
        auto transform = GetComponent<component::Transform>(entity);

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
        
        sf::Text* draw_text = new sf::Text();
        draw_text->setString(text);
        draw_text->setFont(font_);
        draw_text->setCharacterSize(50);
        draw_text->setPosition(
            transform->GetX() * width,
            transform->GetY() * height);
        draw_text->setFillColor(sf::Color::White);
        auto text_drawable = new TextDrawable(draw_text);
        
        if (entity->HasComponent<component::HUD>()) {
            text_drawable->HUD = true;
        }
        
        render_vector->push_back({10, text_drawable});

        if (entity->HasComponent<component::ParentEntity>()) {
            auto parent_transform 
                = entity
                    ->GetComponent<component::ParentEntity>()
                    ->GetParent()
                    ->GetComponent<component::Transform>();
            transform->SetPosition(
                transform->GetX() - parent_transform->GetX(),
                transform->GetY() - parent_transform->GetY());
        }
    }
}

}
