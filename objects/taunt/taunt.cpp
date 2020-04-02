#include "objects/taunt/taunt.h"
#include "collisions/null_collision_box.h"

Taunt::Taunt(Player* player) {
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
	return x_;
}

double Taunt::GetY() {
	return y_;
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