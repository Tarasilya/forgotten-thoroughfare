#include "textures.h"

#include "component/state/window.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <map>

std::map<std::string, sf::Texture*> Textures::textures_;

sf::Texture* Textures::Get(const std::string& file) {
    if (textures_.count(file) == 0) {
        sf::Texture* texture = new sf::Texture();
        if (!texture->loadFromFile(file)){
            std::cerr << "Could not load image " << file;
        }        
        textures_[file] = texture;
    }
    return textures_[file];
}

std::pair<double, double> Textures::GetScaleForSize(const std::string& file, 
        double width, double height, component::Window* window_component) {
    auto texture = Get(file);
    auto window = window_component->GetWindow();

    double x_scale = width * window->getSize().x / texture->getSize().x;
    double y_scale = height * window->getSize().y / texture->getSize().y;

    return {x_scale, y_scale};
}
