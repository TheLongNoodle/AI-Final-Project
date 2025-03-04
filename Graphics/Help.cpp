#include "Help.h"
#include "Restock.h"

// enter current state
void Help::OnEnter(Player* p)
{
	Support* f = dynamic_cast<Support*>(p);
	if (f)
	{
		f->doSomething();
	}
}

void Help::Transition(Player* p)
{
	OnExit(p);
	Support* f = dynamic_cast<Support*>(p);
	if (f)
	{
		if (p->getAmmo() == 0 || p->getHealth() <= SMAX_HEALTH * 0.2)
			f->setCurrentState(new Restock());
	}
}

// exiting current state
void Help::OnExit(Player* p)
{
	Support* f = dynamic_cast<Support*>(p);
	f->setNeedToRestock(true);
}
