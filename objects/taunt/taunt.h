#pragma once

#include <ctime>

#include "objects/passive_object.h"

enum TauntState{MOVE_UP, MOVE_DOWN, STANDBY};

class Taunt : PassiveObject {
private:
	double x_;
	double y_;
	TauntState state_;
	CollisionBox* collision_box_;
	bool visibility_;
	clock_t start_time_;

public:

	const double MVMT_PERIOD = 0.8;


	Taunt();
	void SetVisibility(bool visibility);
	void SetCoords(double x_taunt, double y_taunt);
	void SetStartTime(clock_t time);
	clock_t GetStartTime();
	bool GetVisibility();
	double GetX();
	double GetY();
	CollisionBox* GetCollisionBox() const override;
	bool Pickupable(Player* p) override;
	bool Collidable(Player* p) override;
	void Tick(double dt) override;
};