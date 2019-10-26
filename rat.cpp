#include "rat.h"

const double speed = 0.05;
const double size = 0.02;

Rat::Rat(double x, double y, double i) : x_(x), y_(y), i_(i) {
    collision_box_ = new RectCollisionBox(x - size, y - size, x + size, y + size);
}

CollisionBox* Rat::GetCollisionBox() {
    return collision_box_;
}

void Rat::Tick(double dt){}

bool Rat::ProcessKey(sf::Keyboard::Key key) {
    if (i_ == 0) {
        if (key == sf::Keyboard::W) {
            y_ -= speed;
            return true;
        }
        if (key == sf::Keyboard::A) {
            x_ -= speed;
            return true;
        }
        if (key == sf::Keyboard::S) {
            y_ += speed;
            return true;
        }
        if (key == sf::Keyboard::D) {
            y_ += speed;
            return true;
        }
    }
    else {
        if (key == sf::Keyboard::I) {
            y_ -= speed;
            return true;
        }
        if (key == sf::Keyboard::J) {
            x_ -= speed;
            return true;
        }
        if (key == sf::Keyboard::K) {
            y_ += speed;
            return true;
        }
        if (key == sf::Keyboard::L) {
            y_ += speed;
            return true;
        }
    }
}