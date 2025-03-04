#include "Support.h"
#include "Attack.h"
#include "glut.h"

Support::Support(double xx, double yy, int cow, int t) : Player(xx, yy, MAX_AMMO, MAX_HEALTH, cow, t, new Attack()) {}

void Support::show()
{
	switch (team)
	{
	case 1:
		glColor3d(1, 0.5, 0.5);
		break;
	case 2:
		glColor3d(0.5, 0.5, 1);
	}
	glBegin(GL_POLYGON);
	glVertex2d(x - 0.5, y);
	glVertex2d(x, y + 0.5);
	glVertex2d(x + 0.5, y);
	glVertex2d(x, y - 0.5);
	glEnd();

	// draw ammo
	glColor3d(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2d(x - 0.1, y + 0.1);
	glVertex2d(x - 0.1 + 0.2 * ammo / MAX_AMMO, y + 0.1);
	glEnd();

	// draw health
	glColor3d(0.5, 0, 0.3);
	glBegin(GL_LINES);
	glVertex2d(x - 0.1, y + 0.12);
	glVertex2d(x - 0.1 + 0.2 * health / MAX_HEALTH, y + 0.12);
	glEnd();
}

void Support::doSomething()
{

}