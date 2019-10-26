#include "player.h"
#include "view.h"

#include <iostream>

Player::Player(View* view) : view_(view) {}


bool Player::ProcessKey(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::A) {
        view_->Move(-speed, 0);
        return true;
    }
    if (key == sf::Keyboard::S) {
        view_->Move(0, -speed);
        return true;
    }
    if (key == sf::Keyboard::W) {
        view_->Move(0, speed);
        return true;
    }
    if (key == sf::Keyboard::D) {
        view_->Move(speed, 0);
        return true;
    }

    return false;
}

