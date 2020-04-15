#include "attack.h"

#include "core/game.h"
#include "collisions/rect_collision_box.h"
#include "objects/damageable.h"
#include "objects/player.h"
#include "views/attack_view.h"
#include "painter/painter.h"

const double DMG = 10;

const double WIDTH = 0.1;
const double HEIGHT = 0.033;


Attack::Attack(const Player* player): player_(player), state_(IDLE), charges_(0) {
    start_time_ = -1;
    view_ = new AttackView(this, player, PLAYER_SIZE);
}

void Attack::Trigger() {
    UpdateState();
    if (state_ == IDLE) {
        start_time_ = clock();
        state_ = STARTUP;
        charges_ = 1;
    }
}

CollisionBox* Attack::GetCollisionBox() const {
    return view_->GetCollisionBox();
}

State Attack::GetState() const {
    UpdateState();
    return state_;
}

double Attack::GetActiveTime() const {
    UpdateState();
    if (state_ == STARTUP) {
        return 0;
    }
    return (clock() - start_time_) * 1.0 / CLOCKS_PER_SEC - STARTUP_T;
}


int Attack::GetDirection() const {
    return player_->GetDirection();
}


void Attack::Tick(double dt) {
    UpdateState();
    if (state_ == ACTIVE) {
        Game* game = Game::GetGame();
        for (auto object : game->GetCollision(GetCollisionBox())) {
            if (object == this || object == player_) {
                continue;
            }
            Damageable* damageable = dynamic_cast<Damageable*>(object);
            if (damageable == 0) {
                continue;
            }
            if (charges_ > 0) {
                if (damageable->Damage(DMG)) {
                    charges_--;
                }
            }
        }
    }
}

void Attack::UpdateState() const {
    if (start_time_ == -1) {
        state_ = IDLE;
        return;
    }
    double time_passed = (clock() - start_time_) * 1.0 / CLOCKS_PER_SEC;
    if (time_passed < STARTUP_T) {
        state_ = STARTUP;
    }
    else if (time_passed < STARTUP_T + ACTIVE_T) {
        state_ = ACTIVE;
    }
    else if (time_passed < STARTUP_T + ACTIVE_T + RECOVERY_T) {
        state_ = RECOVERY;
    }
    else {
        state_ = IDLE;
    }
}

bool Attack::Collidable(Player* p) {
    return true;
}
