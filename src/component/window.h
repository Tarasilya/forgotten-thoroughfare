#pragma once

#include "component.h"

#include <SFML/Graphics.hpp>

class Window: public Component {
private:
    sf::RenderWindow* window_;

public:
    ~Window() override;

    void Init(int width, int height);

    sf::RenderWindow* GetWindow();
};
