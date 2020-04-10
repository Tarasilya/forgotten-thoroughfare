#include "taunt.h"

#include "collisions/null_collision_box.h"
#include "objects/player.h"
#include "painter/painter.h"
#include "views/texture_view.h"


const double SIZE = 0.05;
const double MVMT_PERIOD = 0.8;


Taunt::Taunt(Player* player) {
	(new TextureView("pics/taunt2.png", this))
		->SetSize(SIZE, SIZE)
		->SetVisibility(this)
        ->SetZ(4);

	x_ = 0;
	y_ = 0;
	collision_box_ = new NullCollisionBox();
	visibility_ = false;
	start_time_ = clock();
	player_ = player;
}

bool Taunt::GetVisibility() {
	return visibility_;
}

CollisionBox* Taunt::GetCollisionBox() const {
	return collision_box_;
}

bool Taunt::Pickupable(Player* p) {
	return false;
}

bool Taunt::Collidable(Player* p) {
	return true;
}

double Taunt::GetX() {
	return player_->GetX() + x_ - SIZE;
}

double Taunt::GetY() {
	return player_->GetY() + y_ + SIZE;
}

clock_t Taunt::GetStartTime() {
	return start_time_;
}

void Taunt::Launch() {
	visibility_ = true;
	x_ = 0;
	y_ = 0;
	start_time_ = clock();
}

void Taunt::Tick(double dt) {
	if (visibility_) {
        clock_t current_time = clock();
        double taunt_mvmt;
        double taunt_speed = PLAYER_SIZE / MVMT_PERIOD;

        double mvmt_time = (current_time - start_time_) * 1.0 / CLOCKS_PER_SEC;
        if (mvmt_time < MVMT_PERIOD / 2) {
            taunt_mvmt = -taunt_speed * dt;
        }
        else if (mvmt_time < MVMT_PERIOD) {
            taunt_mvmt = taunt_speed * dt;
        }
        else {
            visibility_ = false;
            return;
        }
        y_ += taunt_mvmt;
    }
}

Player* Taunt::GetPlayer() {
	return player_;
}