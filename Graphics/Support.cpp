#include "Support.h"
#include "Attack.h"
#include "Restock.h"
#include "Backup.h"
#include "GroupDef.h"
#include "glut.h"
#include <string>

Support::Support(int xx, int yy, int cow, int t) : Player(xx, yy, SMAX_AMMO, SMAX_HEALTH, cow, t, new Backup()) {} // needs a redo!

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
	glRasterPos2d(xx + 4, yy - 2);
	for (char c : "|") glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	glColor3f(0, 1, 0);
	glRasterPos2d(xx + 5, yy - 2);
	for (char c : std::to_string((int)aid)) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(xx, yy - 3);
	glVertex2f(x, y);
	glEnd();
}

void Support::doSomething()
{
	double dist = 0;
	double closestDist = 1000;
	int help_fl = 0;
	Player* p = nullptr;
	if (needToRestock) // Restock mode
	{
		//search by A* the closest warehouse
		//then enter it's coordinates to the target of the support player
		for (Warehouse* ws : warehouses)
		{
			dist = calcDistToWarehouse(this->getX(), this->getY(), ws);
			if (dist < closestDist)
			{
				closestDist = dist;
				setTarget(ws->getX(), ws->getY());
			}
		}
		//check if the distance between the Support player to the warehouse is 2 or less
		if (dist <= 2)
		{
			//replenishing
			setAmmo(SMAX_AMMO);
			setHealth(SMAX_HEALTH);
			//go back to Backup his team
			dist = 0;
			closestDist = 1000;
			for (Player* po : players)
			{
				if (po->getTeam() == team)
				{
					dist = calcDist(po);
					if (dist < closestDist)
					{
						closestDist = dist;
						setTarget(po->getX(), po->getY());
					}
				}
			}
			needToRestock = false;
		}
		//one step towards the closest warehouse
		AStarTarget();
	}
	else
	{
		//look for team players in need for help (Help)
		for (Player* po : players)
		{
			//the following condition might need to use cowardness factor 
			// or the boolean of the need for supply
			if (po->getTeam() == team && (po->getAmmo() < 1 || po->getHealth() < po->getCowardness()))
			{
				dist = calcDist(po);
				if (dist < closestDist)
				{
					p = po;
					closestDist = dist;
					setTarget(po->getX(), po->getY());
				}
			}
		}

		//check if the distance between the Support player to the team player is 2 or less
		if (dist <= 2 && p != nullptr)
		{
			p->setAmmo(FMAX_AMMO);
			p->setHealth(FMAX_HEALTH);
		}

		//look for the closest team player (Backup)
		for (Player* po : players)
		{
			if (po->getTeam() == team)
			{
				dist = calcDist(po);
				if (dist < closestDist)
				{
					closestDist = dist;
					//in order to not get to close to the player and supply ammo 
					// and health we subtract 2 from the coordinates
					setTarget(po->getX() - 2, po->getY() - 2);  
				}
			}
		}

		//one step towards the current target
		AStarTarget();
	}
}