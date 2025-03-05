#include "Restock.h"
#include "Backup.h"
#include "Groupdef.h"

// enter current state
void Restock::OnEnter(Player* p)
{
		p->setNeedToRestock(true);
		p->doSomething();
}

void Restock::Transition(Player* p)
{
	OnExit(p);
	//check if the ammo and health is on max
	//then go to Backup or Help - previous phase might need 
	// savings in order to go back directly to Help
		if (p->getHealth() == SMAX_HEALTH && p->getAmmo() == SMAX_AMMO)
			p->setCurrentState(new Backup());
	
}

// exiting current state
void Restock::OnExit(Player* p)
{
	p->setNeedToRestock(false);
}
