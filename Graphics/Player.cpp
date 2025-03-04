#include "Player.h"
#include "glut.h"

Player::Player(double xx, double yy, double a, double h, int t, int cow, State* s)
{
	x = xx;
	y = yy;
	ammo = a;
	health = h;
	team = t;
	cowardnessFactor = cow;
	pCurrentState = s;
}

void Player::doSomething()
{
}

void Player::show()
{
}