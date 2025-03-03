#include "Support.h"
#include "glut.h"

Support::Support(double r, double c, int cow, int t) : Player(r, c, cow, t, 250) {}

void Support::play()
{

}

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
	glVertex2d(col - 0.5, row);
	glVertex2d(col, row + 0.5);
	glVertex2d(col + 0.5, row);
	glVertex2d(col, row - 0.5);
	glEnd();
}