#include "Player.h"
#include "glut.h"

Player::Player(double r, double c, int cow, int t, int a)
{
	row = r;
	col = c;
	cowardThresh = cow;
	ammo = 0;
	team = t;
}

void Player::play()
{
}

void Player::show()
{
}