#include "Fighter.h"
#include "Attack.h"
#include "glut.h"

Fighter::Fighter(double xx, double yy, int cow, int t) : Player(xx, yy, FMAX_AMMO, FMAX_HEALTH, cow, t, new Attack()) {}

void Fighter::show()
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
}

void Fighter::doSomething()
{

}