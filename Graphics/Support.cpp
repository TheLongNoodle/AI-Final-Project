#include "Support.h"
#include "Attack.h"
#include "glut.h"

Support::Support(double xx, double yy, int cow, int t) : Player(xx, yy, SMAX_AMMO, SMAX_HEALTH, cow, t, new Attack()) {}

void Support::show()
{
	switch (team)
	{
	case 1:
		glColor3d(1, 0.5, 0.5);
		break;
	case 2:
		glColor3d(0.5, 0.5, 1);
		break;
	}
	glBegin(GL_POLYGON);
	glVertex2d(x - 0.5, y);
	glVertex2d(x, y + 0.5);
	glVertex2d(x + 0.5, y);
	glVertex2d(x, y - 0.5);
	glEnd();
}

void Support::doSomething()
{

}