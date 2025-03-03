#include "Fighter.h"
#include "glut.h"

Fighter::Fighter(double r, double c, int cow, int t) : Player(r, c, cow, t, 30) {}


void Fighter::play()
{

}

void Fighter::show()
{
	switch (team)
	{
	case 1:
		glColor3d(0.8, 0, 0);
		break;
	case 2:
		glColor3d(0, 0, 0.8);
	}
	glBegin(GL_POLYGON);
	glVertex2d(col - 0.5, row);
	glVertex2d(col, row + 0.5);
	glVertex2d(col + 0.5, row);
	glVertex2d(col, row - 0.5);
	glEnd();
}