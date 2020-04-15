#pragma once

#include <ctime>

#include "objects/passive_object.h"
#include "views/visible.h"
#include "views/position.h"

class Player;

class Taunt : public PassiveObject, public Visible, public Position {
private:
	double x_;
	double y_;
	Player* player_;
	CollisionBox* collision_box_;
	bool visibility_;
	clock_t start_time_;

public:
	Taunt(Player* player);
	void Launch();
	clock_t GetStartTime();
	bool GetVisibility() override;
	Player* GetPlayer();
	double GetX() const override;
	double GetY() const override;
	CollisionBox* GetCollisionBox() const override;
	bool Pickupable(Player* p) override;
	bool Collidable(Player* p) override;
	void Tick(double dt) override;
};