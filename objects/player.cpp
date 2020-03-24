#include <algorithm>
#include <iostream>
#include <utility>

#include <math.h>
#include <stdlib.h>

#include "player.h"

#include "core/game.h"
#include "collisions/rect_collision_box.h"

const double speed = 0.002;
const double size = 0.1;

Player::Player(double x, double y, double i, Game* game) : x_(x), y_(y), i_(i), game_(game) {
    collision_box_ = new RectCollisionBox(x, y, x + size, y + size);
    if (i_ == 0) {
        moves[UP] = sf::Keyboard::W;
        moves[LEFT] = sf::Keyboard::A;
        moves[DOWN] = sf::Keyboard::S;
        moves[RIGHT] = sf::Keyboard::D;
    }
    else {
        moves[UP] = sf::Keyboard::I;
        moves[LEFT] = sf::Keyboard::J;
        moves[DOWN] = sf::Keyboard::K;
        moves[RIGHT] = sf::Keyboard::L;
    }
}

CollisionBox* Player::GetCollisionBox() {
    return collision_box_;
}

void Player::Tick(double dt) {
    double vertical_speed = 0;
    double horizontal_speed = 0;
    if (sf::Keyboard::isKeyPressed(moves[UP])) {
        vertical_speed -= speed;
    }
    if (sf::Keyboard::isKeyPressed(moves[DOWN])) {
        vertical_speed += speed;
    }
    if (sf::Keyboard::isKeyPressed(moves[LEFT])) {
        horizontal_speed -= speed;
    }
    if (sf::Keyboard::isKeyPressed(moves[RIGHT])) {
        horizontal_speed += speed;
    }
    Move(horizontal_speed, vertical_speed);
}

bool Player::ProcessKey(sf::Keyboard::Key key, bool pressed) {
    return false;
}

void Player::Move(double dx, double dy) {
    collision_box_->Move(dx, dy);
    for (auto object : game_->GetCollision(collision_box_)) {
        if (object != this) {
            std::pair<double, double> correction = collision_box_->GetCorrection((RectCollisionBox*) object->GetCollisionBox(), dx, dy);
            double new_dx = -copysign(std::min(correction.first, abs(dx)), dx);
            double new_dy = -copysign(std::min(correction.second, abs(dy)), dy);
            collision_box_->Move(new_dx, new_dy);
            x_ += dx + new_dx;
            y_ += dy + new_dy;

            return;
        }
    }
    x_ += dx;
    y_ += dy;
}

double Player::GetX() {
    return x_;
}
double Player::GetY() {
    return y_;
}
