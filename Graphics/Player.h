#pragma once
#include "State.h"
#include "math.h"

class Player
{
protected:
	int x, y;
	double ammo;
	double health;
	int targetX, targetY;
	State* pCurrentState;
	int team;
	int cowardnessFactor;
public:
	Player(int xx, int yy, double a, double h, int cow, int t, State* s);
	virtual void show(int xx, int yy);
	virtual void doSomething();
	void setTarget(double x, double y) { targetX = x;  targetY = y; }
	void setCurrentState(State* ps) { pCurrentState = ps; }
	void setAmmo(double a) { ammo = a; }
	void setHealth(double h) { health = h; }
	State* getCurrentState() { return pCurrentState; }
	double getAmmo() { return ammo; }
	double getHealth() { return health; }
	int getTargetX() { return targetX; }
	int getTargetY() { return targetY; }
	int getX() { return x; }
	int getY() { return y; }
	int getTeam() { return team; }
	int getCowardness() { return cowardnessFactor; }
	double calcDist(Player* p) { return sqrt((x * p->getX()) + (y * p->getY())); }
	bool checkNeighbour(int row, int col, Cell* pCurrent);
	void AStarTarget();

};