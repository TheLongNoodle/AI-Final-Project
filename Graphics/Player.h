#pragma once
#include "State.h"

class Player
{
protected:
	double x, y;
	double ammo;
	double health;
	bool isMoving, isReplenishing, isFiring, isTreating; //Replenishing stands for reloading and healing
	double targetX, targetY;
	State* pCurrentState;
	int team;
	int cowardnessFactor;
public:
	Player(double xx, double yy, double a, double h, int cow, int t, State* s);
	virtual void show(int xx, int yy);
	virtual void doSomething();
	void setIsMoving(bool value) { isMoving = value; }
	void setIsReplenishing(bool value) { isReplenishing = value; }
	void setIsFiring(bool value) { isFiring = value; }
	void setIsTreating(bool value) { isTreating = value; }
	void setTarget(double x, double y) { targetX = x;  targetY = y; }
	void setCurrentState(State* ps) { pCurrentState = ps; }
	State* getCurrentState() { return pCurrentState; }
	double getAmmo() { return ammo; }
	double getHealth() { return health; }
};