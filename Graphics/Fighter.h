#pragma once
#include "Player.h"
#include "State.h"
const double FSPEED = 0.01;
const double FMAX_HEALTH = 100;
const double FMAX_AMMO = 60;
const double FMIN_AMMO = 0;

class Fighter : public Player
{
public:
	Fighter(double xx, double yy, int cow, int t);
	void show();
	void doSomething();
};