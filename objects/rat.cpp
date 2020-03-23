#include <algorithm>
#include <iostream>
#include <utility>

#include <math.h>
#include <stdlib.h>

#include "rat.h"

#include "core/game.h"
#include "collisions/rect_collision_box.h"

const double speed = 0.02;
const double size = 0.1;

Rat::Rat(double x, double y, double i, Game* game) : x_(x), y_(y), i_(i), game_(game) {
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

CollisionBox* Rat::GetCollisionBox() {
    return collision_box_;
}

void Rat::Tick(double dt) {
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

bool Rat::ProcessKey(sf::Keyboard::Key key, bool pressed) {
    return false;
}

void Rat::Move(double dx, double dy) {
    collision_box_->Move(dx, dy);
    for (auto object : game_->GetCollision(collision_box_)) {
        if (object != this) {
            std::pair<double, double> correction = collision_box_->GetCorrection((RectCollisionBox*) object->GetCollisionBox(), dx, dy);
            double new_dx = -copysign(std::min(correction.first, abs(dx)), dx);
            double new_dy = -copysign(std::min(correction.second, abs(dy)), dy);
            collision_box_->Move(new_dx, new_dy);
            x_ += dx + new_dx;
            y_ += dy + new_dy;

            view->PrintBounce();
            ((Rat*) object)->view->PrintBounce();


            std::cerr << "Intended horizontal: " << dx << "; Actual horizontal: " << dx + new_dx << "\n";
            std::cerr << "Intended vertical: "   << dy << "; Actual vertical: " << dy + new_dy << "\n";
            

            std::cerr << "Self actual x: " << x_ << "\n";
            std::cerr << "Self actual y: " << y_ << "\n";

            std::cerr << "Other actual x: " << ((Rat*) object)->x_ << "\n";
            std::cerr << "Other actual y: " << ((Rat*) object)->y_ << "\n";


            return;
        }
    }
    x_ += dx;
    y_ += dy;
}

double Rat::GetX() {
    return x_;
}
double Rat::GetY() {
    return y_;
}
