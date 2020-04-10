#include <algorithm>
#include <iostream>
#include <utility>
#include <ctime>

#include <math.h>
#include <stdlib.h>

#include "player.h"

#include "core/game.h"
#include "collisions/rect_collision_box.h"
#include "painter/painter.h"
#include "player/hp_bar.h"
#include "objects/taunt/taunt.h"
#include "objects/player/attack.h"
<<<<<<< HEAD
#include "views/texture_view.h"
=======
#include "backpack/craft.h"
>>>>>>> Initial Crafting Functionality

const double speed = 0.4;
const double taunt_size = 0.05;

const double MAX_HP = 100;
const double DMG = 10;

Player::Player(double x, double y, Game* game) : x_(x), y_(y), game_(game), backpack_visibility_(false) {
    (new TextureView("pics/mouse_assassin.jpg", this))->SetSize(PLAYER_SIZE, PLAYER_SIZE)->SetZ(1);

    hp_bar_ = new HpBar(MAX_HP, this);
    taunt_ = new Taunt(this);
    attack_ = new Attack(this);
    game->AddObject(attack_);
    game->AddObject(taunt_);
    
    collision_box_ = new RectCollisionBox(x, y, x + PLAYER_SIZE, y + PLAYER_SIZE);
    moves[UP] = sf::Keyboard::I;
    moves[LEFT] = sf::Keyboard::J;
    moves[DOWN] = sf::Keyboard::K;
    moves[RIGHT] = sf::Keyboard::L;
    moves[BACKPACK] = sf::Keyboard::O;
    moves[DROP] = sf::Keyboard::Q;
    moves[PICKUP] = sf::Keyboard::E;
    moves[DAMAGE] = sf::Keyboard::A;
    moves[HEAL] = sf::Keyboard::S;
    moves[TAUNT] = sf::Keyboard::F;
    moves[ATTACK] = sf::Keyboard::R;
    moves[CRAFT_SWORD] = sf::Keyboard::V;
    moves[CRAFT_CIDER] = sf::Keyboard::B;
    backpack_ = new Backpack();
}

CollisionBox* Player::GetCollisionBox() const {
    return collision_box_;
}

void Player::Tick(double dt) {
    Move(horizontal_speed_ * dt, vertical_speed_ * dt);
    vertical_speed_ = 0;
    horizontal_speed_ = 0;
}


bool Player::ProcessKey(sf::Keyboard::Key key, bool pressed, bool repeated) {
    if (key == moves[UP]) {
        vertical_speed_ -= speed;
        return true;
    }
    if (key == moves[DOWN]) {
        vertical_speed_ += speed;
        return true;
    }
    if (key == moves[LEFT]) {
        horizontal_speed_ -= speed;
        return true;
    }
    if (key == moves[RIGHT]) {
        horizontal_speed_ += speed;
        return true;
    }

    if (key == moves[PICKUP]) {
        PickUpItems();
        return true;
    }

    if (key == moves[BACKPACK] && !repeated) {
        backpack_visibility_ = !backpack_visibility_;
        return true;
    }
    if (key == moves[DAMAGE] && !repeated) {
        Damage(DMG);
        return true;
    }
    if (key == moves[HEAL] && !repeated) {
        Damage(-DMG);
        return true;
    }
    if (key == moves[DROP] && !repeated) {
        backpack_->DropItem(x_, y_);
        return true;
    }    
    if (key == moves[TAUNT] && !repeated) {
        taunt_->Launch();
        return true;
    }
    if (key == moves[ATTACK] && !repeated) {
        attack_->Trigger();
        return true;
    }
    if (key == moves[CRAFT_SWORD] && !repeated) {
        Craft::CraftItem(ItemType::SWORD, this);
    }
    if (key == moves[CRAFT_CIDER] && !repeated) {
        Craft::CraftItem(ItemType::CIDER, this);
    }
    return false;
}


void Player::Damage(double dmg) {
    hp_bar_->Change(-dmg);
}


void Player::Move(double dx, double dy) {
    Painter* painter = Painter::GetPainter();
    collision_box_->Move(dx, dy);
    
    for (auto object : game_->GetCollision(collision_box_)) {
        if (object != this && !object->Collidable(this)) {
            std::pair<double, double> correction = collision_box_->GetCorrection((RectCollisionBox*) object->GetCollisionBox(), dx, dy);
            double new_dx = -copysign(std::min(correction.first, abs(dx)), dx);
            double new_dy = -copysign(std::min(correction.second, abs(dy)), dy);
            collision_box_->Move(new_dx, new_dy);
            x_ += dx + new_dx;
            y_ += dy + new_dy;
            painter->PlayerMoved(x_, y_);

            return;
        }
    }
    x_ += dx;
    y_ += dy;
    painter->PlayerMoved(x_, y_);
}

void Player::PickUpItems() {
    for (auto object : game_->GetCollision(collision_box_)) {
        if (object != this && object->Pickupable(this)) {
            backpack_->PickItem((Item*) object);
            return;
        }
    }
}

double Player::GetX() {
    return x_;
}
double Player::GetY() {
    return y_;
}

Backpack* Player::GetBackpack() {
    return backpack_;
}

Taunt* Player::GetTaunt() {
    return taunt_;
}

bool Player::GetBackpackVisibility() {
    return backpack_visibility_;
}

bool Player::Collidable(Player* p) {
    return false;
}

bool Player::Pickupable(Player* p) {
    return false;
}
