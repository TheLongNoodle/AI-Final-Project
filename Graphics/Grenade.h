#pragma once
#include "Bullet.h"

const int NUM_BULLETS = 20;

class Grenade
{
private:
	double row, col;
	Bullet* bullets[NUM_BULLETS];
	int team;
public:
	Grenade(double r, double c, int t);
	void explode();
	void expand(int maze[MSZ][MSZ]);
	void show();
	void SimulateExplosion(int maze[MSZ][MSZ], double sm[MSZ][MSZ]);
};

