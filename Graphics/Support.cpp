#include "Support.h"
#include "Attack.h"
#include "glut.h"
#include <string>

Support::Support(double xx, double yy, int cow, int t) : Player(xx, yy, SMAX_AMMO, SMAX_HEALTH, cow, t, new Attack()) {}

void Support::show(int xx, int yy)
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

	// Draw HUD
	glColor3f(0, 0, 0);
	glRasterPos2d(xx - 3, yy);
	for (char c : "Support") glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
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
	glVertex2f(xx, yy - 3);
	glVertex2f(x, y);
	glEnd();
}

void Support::doSomething()
{

}