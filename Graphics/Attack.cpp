#include "Attack.h"
#include "Defense.h"
#include "Groupdef.h"

// enter current state
void Attack::OnEnter(Player* p)
{
	// Finds closest enemy
	double dist = 0;
	double closestDist = 1000;
	for (Player* po : players)
	{
		if (po->getTeam() != p->getTeam())
		{
			dist = p->calcDist(po);
			if (dist < closestDist)
			{
				closestDist = dist;
				p->setTarget(po->getX(), po->getY());
			}
		}
	}
}

void Attack::Transition(Player* p)
{
	OnExit(p);
	Fighter* f = dynamic_cast<Fighter*>(p);
	if (f)
	{
		double angle = f->hasClearShot(f->getTargetX(), f->getTargetY());
		if (angle != 0.0) // Shoot
		{
			bullets.push_back(new Bullet(f->getX(), f->getY(), angle, f->getTeam()));
		}
		else // AStar move to closest enemy
		{
			f->AStarTarget();
		}
	}
}

// exiting current state
void Attack::OnExit(Player* p)
{
	Fighter* f = dynamic_cast<Fighter*>(p);
	if (f)
	{
		if (f->getHealth() < f->getCowardness() || f->getAmmo() < 1)
		{
			f->setCurrentState(new Defense());
			f->setNeed(true);
		}
	}
}
