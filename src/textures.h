#pragma once

#include <SFML/Graphics.hpp>

#include <map>

namespace component {
    class Window;
}

class Textures {
public:
    static std::map<std::string, sf::Texture*> textures_;

    static sf::Texture* Get(const std::string& file);

    static std::pair<double, double> GetScaleForSize(const std::string& file, 
        double width, double height, component::Window* window_component);
};
