#include "Warehouse.h"
#include "glut.h"

Warehouse::Warehouse(double xx, double yy)
{
	x = xx;
	y = yy;
}

void Warehouse::show()
{
	glColor3d(0, 0, 0);
	glPointSize(1.0); // point size
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
}
