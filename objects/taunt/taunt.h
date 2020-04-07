#pragma once

#include <ctime>

#include "objects/passive_object.h"

#include "objects/player.h"

class Taunt : public PassiveObject, public Visible, public Position {
private:
	double x_;
	double y_;
	Player* player_;
	CollisionBox* collision_box_;
	bool visibility_;
	clock_t start_time_;

public:

	const double MVMT_PERIOD = 0.8;


	Taunt(Player* player);
	void SetVisibility(bool visibility);
	void SetCoords(double x_taunt, double y_taunt);
	void SetStartTime(clock_t time);
	clock_t GetStartTime();
	bool GetVisibility() override;
	Player* GetPlayer();
	double GetX() override;
	double GetY() override;
	CollisionBox* GetCollisionBox() const override;
	bool Pickupable(Player* p) override;
	bool Collidable(Player* p) override;
	void Tick(double dt) override;
};