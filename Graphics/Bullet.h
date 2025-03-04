#pragma once
#include "definitions.h"
class Bullet
{
private: 
	double x, y;
	double dir_angle;
	double dirX, dirY;
	double speed;
	bool isMoving;
	int team;
public:
	Bullet(double xx, double yy, double angle, int t);
	void move(int maze[MSZ][MSZ]);
	void show();
	void setIsMoving(bool value) { isMoving = value; }
	bool getIsMoving() { return isMoving; }
	void SimulateExplosion(int maze[MSZ][MSZ], double sm[MSZ][MSZ]);

};

