#include "objects/taunt/taunt.h"
#include "collisions/null_collision_box.h"

const double SIZE = 0.05;

Taunt::Taunt(Player* player) {
	View* view = new TextureView("pics/taunt2.png", this).SetZ(4).SetSize(SIZE, SIZE).SetVisibility(this);

	x_ = 0;
	y_ = 0;
	collision_box_ = new NullCollisionBox();
	visibility_ = false;
	start_time_ = clock();
	player_ = player;
}

void Taunt::SetVisibility(bool visibility) {
	visibility_ = visibility;
}

bool Taunt::GetVisibility() {
	return visibility_;
}

void Taunt::SetCoords(double x_taunt, double y_taunt) {
	x_ = x_taunt;
	y_ = y_taunt;
}

void Taunt::SetStartTime(clock_t time) {
	start_time_ = time;
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
	return player->GetX() + x_ - SIZE;
}

double Taunt::GetY() {
	return player->GetY() + y_ - SIZE;
}

clock_t Taunt::GetStartTime() {
	return start_time_;
}

void Taunt::Tick(double dt) {
	return;
}

Player* Taunt::GetPlayer() {
	return player_;
}