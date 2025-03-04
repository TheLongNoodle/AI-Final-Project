#pragma once
#include "State.h"

class Player
{
protected:
	double x, y;
	double ammo;
	double health;
	bool isMoving, isReplenishing, isFiring; //Replenishing stands for reloading and healing
	double targetX, targetY;
	State* pCurrentState;
	int team;
	int cowardnessFactor;
public:
	Player(double xx, double yy, double a, double h, int t, int cow, State* s);
	virtual void show();
	virtual void doSomething();
	double getAmmo() { return ammo; }
	double getHealth() { return health; }
};