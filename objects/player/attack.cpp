#include "attack.h"

#include "core/game.h"
#include "collisions/rect_collision_box.h"
#include "objects/damageable.h"
#include "objects/player.h"
#include "views/attack_view.h"
#include "painter/painter.h"

const double STARTUP_T = 0.5;
const double ACTIVE_T = 0.2;
const double RECOVERY_T = 0;

const double DMG = 10;

const double WIDTH = 0.1;
const double HEIGHT = 0.033;


Attack::Attack(const Player* player): player_(player), state_(IDLE), charges_(0) {
    start_time_ = -1;
    new AttackView(this);
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
    RectCollisionBox* box = (RectCollisionBox*) player_->GetCollisionBox(); 
    double y1 = (box->y1 + box->y2) / 2 - HEIGHT / 2;

    return new RectCollisionBox(box->x1 - WIDTH, y1, box->x1, y1 + HEIGHT);
}

State Attack::GetState() const {
    UpdateState();
    return state_;
}

void Attack::Tick(double dt) {
    UpdateState();
    if (state_ == ACTIVE) {
        Game* game = Game::GetCurrentGame();
        for (auto object : game->GetCollision(GetCollisionBox())) {
            if (object == this) {
                continue;
            }
            Damageable* damageable = dynamic_cast<Damageable*>(object);
            if (damageable == 0) {
                continue;
            }
            if (charges_ > 0) {
                damageable->Damage(DMG);
                charges_--;
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
