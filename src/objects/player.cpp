#include <algorithm>
#include <iostream>
#include <utility>
#include <ctime>

#include <math.h>
#include <stdlib.h>

#include "player.h"

#include "backpack/craft.h"
#include "core/game.h"
#include "collisions/rect_collision_box.h"
#include "painter/painter.h"
#include "player/hp_bar.h"
#include "objects/items/stick/stick.h"
#include "objects/items/apple/apple.h"
#include "objects/taunt/taunt.h"
#include "objects/player/attack.h"
#include "views/backpack_view.h"
#include "views/craft_view.h"
#include "views/player_view.h"
#include "views/texture_view.h"
#include "views/view.h"

const double speed = 0.4;
const double taunt_size = 0.05;

const double MAX_HP = 100;
const double DMG = 10;


Player::Player(double x, double y, Game* game, bool authority) 
        : x_(x), y_(y), game_(game), backpack_visibility_(false), authority_(authority) {
    view_ = new PlayerView(this, "pics/default_warrior2.png");

    hp_bar_ = new HpBar(MAX_HP, this);
    taunt_ = new Taunt(this);
    attack_ = new Attack(this);
    info_status_ = NO_MENU;
    
    collision_box_ = new RectCollisionBox(x, y, x + PLAYER_SIZE, y + PLAYER_SIZE);

    InitBackpack();
}

void Player::InitBackpack() {
    backpack_ = new Backpack();

    for (int i = 0; i < 100; i++) {
        Stick* stick = new Stick(); 
        Apple* apple = new Apple();

        backpack_->AddItem(stick);
        backpack_->AddItem(apple);
    }

    BackpackView* backpack_view = new BackpackView(backpack_, this);
}

CollisionBox* Player::GetCollisionBox() const {
    return collision_box_;
}

void Player::SetCraftView(CraftView* craft_view) {
    craft_view_ = craft_view;
}

void Player::Tick(double dt) {
    Move(horizontal_speed_ * dt, vertical_speed_ * dt);
    vertical_speed_ = 0;
    horizontal_speed_ = 0;
}

void Player::ActionUp() {
    vertical_speed_ -= speed;
}
void Player::ActionDown() {
    vertical_speed_ += speed;
}
void Player::ActionLeft() {
    direction_ = -1;
    horizontal_speed_ -= speed;
}
void Player::ActionRight() {
    direction_ = 1;
    horizontal_speed_ += speed;
}
void Player::ActionBackpack() {
    switch(info_status_) {
        case NO_MENU:
        case CRAFT_MENU:
            info_status_ = BACKPACK_MENU;
            break;
        
        case BACKPACK_MENU:
            info_status_ = NO_MENU;
            break;
    }
}
void Player::ActionDrop() {
    backpack_->DropItem(x_, y_);    
}
void Player::ActionPickup() {
    auto objects = game_->GetCollision(collision_box_);
    for (auto object : objects) {
        if (object != this && object->Pickupable(this)) {
            backpack_->PickItem((Item*) object);
            return;
        }
    }
}

void Player::ActionTaunt() {
    taunt_->Launch();
}

void Player::ActionAttack() {
    attack_->Trigger();
}

void Player::ActionCraftNow() {
    if (info_status_ == CRAFT_MENU) {
        Craft::CraftItem(Item::GetCraftableTypes()[craft_view_->GetCurrentItem()], this);
        taunt_->Launch();
    } 
}

void Player::ActionMenuInteraction() {
    if (info_status_ == CRAFT_MENU) {
        craft_view_->ChangeCurrentItem();
    }
}

void Player::ActionCraft() {
    switch(info_status_) {

        case NO_MENU:
        case BACKPACK_MENU:
            info_status_ = CRAFT_MENU;
            break;

        case CRAFT_MENU:
            info_status_ = NO_MENU;
            break;
    }    
}


int Player::GetDirection() const {
    return direction_;
}

bool Player::Damage(double dmg) {
    hp_bar_->Change(-dmg);
    if (hp_bar_->GetCurrent() < 1) {
        Painter::GetPainter()->RemoveView(view_);
        view_ = new PlayerView(this, "pics/warrior3.png");
    }
    return true;
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

            if (authority_) {
                painter->PlayerMoved(x_, y_);
            }

            return;
        }
    }
    x_ += dx;
    y_ += dy;

    if (authority_) {
        painter->PlayerMoved(x_, y_);
    }
}

double Player::GetX() const {
    return x_;
}
double Player::GetY() const {
    return y_;
}

Backpack* Player::GetBackpack() {
    return backpack_;
}

Taunt* Player::GetTaunt() {
    return taunt_;
}

InfoStatus Player::GetInfoStatus() {
    return info_status_;
}

bool Player::Collidable(Player* p) {
    return true;
}

bool Player::Pickupable(Player* p) {
    return false;
}
