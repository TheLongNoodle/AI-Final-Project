#include "Fighter.h"
#include "Attack.h"
#include "glut.h"
#include <string>

Fighter::Fighter(double xx, double yy, int cow, int t) : Player(xx, yy, FMAX_AMMO, FMAX_HEALTH, cow, t, new Attack()) {}

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

}