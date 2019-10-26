#pragma once

#include <SFML/Window.hpp>

class View;

const double speed = 0.1;

class Player {
    View* view_;
public:
    Player(View* view);

    bool ProcessKey(sf::Keyboard::Key key);
};