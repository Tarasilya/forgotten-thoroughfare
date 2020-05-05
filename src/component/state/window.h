#pragma once

#include "component/component.h"

#include <SFML/Graphics.hpp>


namespace component {

class Window: public Component {
private:
    sf::RenderWindow* window_;

public:
    void Init(int width, int height);

    sf::RenderWindow* GetWindow();
};

}
