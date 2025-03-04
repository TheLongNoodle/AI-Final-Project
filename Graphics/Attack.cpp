#include "Attack.h"
#include "Defense.h"
#include "Groupdef.h"

// enter current state
void Attack::OnEnter(Player* p)
{
	Fighter* f = dynamic_cast<Fighter*>(p);
	if (f)
	{
		f->setNeed(false);
		f->doSomething();
	}
}

void Attack::Transition(Player* p)
{
	OnExit(p);
	Fighter* f = dynamic_cast<Fighter*>(p);
	if (f)
		if (f->getHealth() < f->getCowardness() || f->getAmmo() < 1)
			f->setCurrentState(new Defense());
}

// exiting current state
void Attack::OnExit(Player* p)
{
	Fighter* f = dynamic_cast<Fighter*>(p);
	if (f)
		f->setNeed(true);
}
