#include "Bullet.h"
#include <math.h>
#include "glut.h"

// angle is in radians
Bullet::Bullet(double xx, double yy, double angle, int t)
{
	x = xx;
	y = yy;
	dir_angle = angle;
	dirX = cos(angle);
	dirY = sin(angle);
	speed = 0.3;
	team = t;
	isMoving = true;
}

void Bullet::move(int maze[MSZ][MSZ])
{
	if (isMoving)
	{
		x += speed * dirX;
		y += speed * dirY;
		if (maze[(int)y][(int)x] == WALL)
			isMoving = false;
	}
}

void Bullet::show()
{
	switch (team)
	{
	case 1:
		glColor3d(1, 0, 0);
		break;
	case 2:
		glColor3d(0, 0, 1);
		break;
	}
	glBegin(GL_POLYGON);
	glVertex2d(x - 0.1, y);
	glVertex2d(x , y+ 0.1);
	glVertex2d(x + 0.1, y);
	glVertex2d(x , y- 0.1);
	glEnd();
}

void Bullet::SimulateExplosion(int maze[MSZ][MSZ], double sm[MSZ][MSZ])
{
	isMoving = true;
	while (isMoving)
	{
		sm[(int)y][(int)x] += SECURITY_FACTOR;
		move(maze);
	}
}
