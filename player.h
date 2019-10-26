#pragma once

#include <SFML/Window.hpp>

const double speed = 0.01;

class Player {
    View* view_;
public:
    Player();

    bool ProcessKey(sf::Keyboard::Key key);
};