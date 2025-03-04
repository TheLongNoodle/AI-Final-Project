#include "Attack.h"
#include "Defence.h"
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
	if (p->getHealth() < p->getCowardness() || p->getAmmo() < 1)
		p->setCurrentState(new Defence());
}
