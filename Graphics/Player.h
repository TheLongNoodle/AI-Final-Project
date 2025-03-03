#pragma once

class Player
{
protected:
	int row, col;
	int health = 100;
	int ammo;
	int cowardThresh;
	int team;
public:
	Player(double r, double c, int cow, int t, int a);
	virtual void play();
	virtual void show();
};