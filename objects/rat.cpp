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
}

CollisionBox* Rat::GetCollisionBox() {
    return collision_box_;
}

void Rat::Tick(double dt){}

bool Rat::ProcessKey(sf::Keyboard::Key key) {
    if (i_ == 0) {
        if (key == sf::Keyboard::W) {
            Move(0, -speed);
            return true;
        }
        if (key == sf::Keyboard::A) {
            Move(-speed, 0);
            return true;
        }
        if (key == sf::Keyboard::S) {
            Move(0, speed);
            return true;
        }
        if (key == sf::Keyboard::D) {
            Move(speed, 0);
            return true;
        }
    }
    else {
        if (key == sf::Keyboard::I) {
            Move(0, -speed);
            return true;
        }
        if (key == sf::Keyboard::J) {
            Move(-speed, 0);
            return true;
        }
        if (key == sf::Keyboard::K) {
            Move(0, speed);
            return true;
        }
        if (key == sf::Keyboard::L) {
            Move(speed, 0);
            return true;
        }
    }

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
