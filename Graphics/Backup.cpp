#include "Backup.h"
#include "Restock.h"
#include "Groupdef.h"

// enter current state
void Backup::OnEnter(Player* p)
{
	p->setNeedToRestock(false);
	p->doSomething();
}

void Backup::Transition(Player* p)
{
	OnExit(p);
	if (p->getAmmo() <= SMAX_AMMO * 0.2 || p->getHealth() <= SMAX_HEALTH * 0.2)
	{
		p->setCurrentState(new Restock());
	}
}

// exiting current state
void Backup::OnExit(Player* p)
{
	p->setNeedToRestock(true);
}
