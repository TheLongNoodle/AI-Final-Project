#include "Backup.h"
#include "Restock.h"
#include "Groupdef.h"

// enter current state
void Backup::OnEnter(Player* p)
{
	Support* f = dynamic_cast<Support*>(p);
	if (f)
	{
		f->doSomething();
	}
}

void Backup::Transition(Player* p)
{
	OnExit(p);
	Support* f = dynamic_cast<Support*>(p);
	if (f)
	{
		if (p->getAmmo() <= SMAX_AMMO * 0.2 || p->getHealth() <= SMAX_HEALTH * 0.2)
			f->setCurrentState(new Restock());
	}
}

// exiting current state
void Backup::OnExit(Player* p)
{
	Support* f = dynamic_cast<Support*>(p);
	f->setNeedToRestock(true);
}
