#include "Defense.h"
#include "Attack.h"

// enter current state
void Defense::OnEnter(Player* p)
{
	p->setNeed(true);
	p->doSomething();

}

void Defense::Transition(Player* p)
{
	if (p->getHealth() >= p->getCowardness() && p->getAmmo() >= 1)
	{
		OnExit(p);
		p->setCurrentState(new Attack());
	}
}

// exiting current state
void Defense::OnExit(Player* p)
{
	p->setNeed(false);
}
