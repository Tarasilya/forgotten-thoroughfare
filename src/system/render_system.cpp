#include "render_system.h"

#include "component/sprite_drawable.h"
#include "component/window.h"
#include "entity.h"
#include "system_manager.h"
#include "type.h"

#include <iostream>


RenderSystem::RenderSystem(SystemManager* manager): System(manager) {
    std::cerr << "RenderSystem cons" << std::endl;
    int size = sf::VideoMode::getDesktopMode().height * 0.9;
    auto window_component = system_manager_->GetComponentFromState<Window>();
    window_component->Init(size, size);


    required_components_.insert(type<SpriteDrawable>());
}

void RenderSystem::Tick(double dt) {
    auto window = system_manager_->GetComponentFromState<Window>()->GetWindow();

    window->clear({0, 0, 0});
    for (auto entity: entities_) {
        auto sprite_drawable = entity->GetComponent<SpriteDrawable>();
        auto file = sprite_drawable->GetDrawable();

        if (textures_.count(file) == 0) {
            sf::Texture* texture = new sf::Texture();
            if (!texture->loadFromFile(file)){
                std::cerr << "Could not load image " << file;
            }        
            textures_[file] = texture;
        }
        sf::Sprite sprite;
        sprite.setTexture(*textures_[file]);
        window->draw(sprite);
    }
    window->display();
}
