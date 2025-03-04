#pragma once
#include "Player.h"
#include "State.h"
const double SSPEED = 0.0001;
const double SMAX_HEALTH = 100;
const double SMAX_AID = 1000;
const double SMAX_AMMO = 200;
const double SMIN_AMMO = 0;

class Support : public Player
{
private:
	double aid = SMAX_AID;
public:
	Support(double xx, double yy, int cow, int t);
	void show(int xx, int yy);
	void doSomething();
};