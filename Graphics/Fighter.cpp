#include "Fighter.h"
#include "Attack.h"
#include "glut.h"
#include "GroupDef.h"
#include <string>

Fighter::Fighter(int xx, int yy, int cow, int t) : Player(xx, yy, FMAX_AMMO, FMAX_HEALTH, cow, t, new Attack()) {}

void Fighter::show(int xx, int yy)
{
	switch (team)
	{
	case 1:
		glColor3d(0.8, 0, 0);
		break;
	case 2:
		glColor3d(0, 0, 0.8);
		break;
	}
	glBegin(GL_POLYGON);
	glVertex2d(x - 0.5, y);
	glVertex2d(x, y + 0.5);
	glVertex2d(x + 0.5, y);
	glVertex2d(x, y - 0.5);
	glEnd();

	// Draw HUD
	glColor3f(0, 0, 0);
	glRasterPos2d(xx - 3, yy);
	for (char c : "Fighter") glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	glColor3f(0, 1, 0);
	glRasterPos2d(xx - 3, yy - 2);
	for (char c : std::to_string((int)health)) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	glColor3f(0, 0, 0);
	glRasterPos2d(xx, yy - 2);
	for (char c : "|") glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	glColor3f(0, 0, 0);
	glRasterPos2d(xx + 1, yy - 2);
	for (char c : std::to_string((int)ammo)) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(xx, yy - 2);
	glVertex2f(x, y);
	glEnd();

}

void Fighter::doSomething()
{
	if (!needSupply) // Attack mode
	{
		// Finds closest enemy
		double dist = 0;
		double closestDist = 1000;
		for (Player* po : players)
		{
			if (po->getTeam() != team)
			{
				dist = calcDist(po);
				if (dist < closestDist)
				{
					closestDist = dist;
					setTarget(po->getX(), po->getY());
				}
			}
		}
		double angle = hasClearShot(targetX, targetY);
		if (angle != 0.0) // Shoot
		{
			bullets.push_back(new Bullet(x, y, angle, team));
		}
		else // AStar move to closest enemy
		{
			AStarTarget();
		}
	}
	else // Defence mode
	{

	}
}

double Fighter::hasClearShot(int xx, int yy) //returns the angle if player has clear shot to position, 0 otherwise (IN RADIANS)
{
	return 0.0;
}
