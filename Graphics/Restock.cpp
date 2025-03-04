#include "Restock.h"
#include "Backup.h"
#include "Groupdef.h"

// enter current state
void Restock::OnEnter(Player* p)
{
	Support* f = dynamic_cast<Support*>(p);
	if (f)
	{
		f->setNeedToRestock(false);
		f->doSomething();
	}
}

void Restock::Transition(Player* p)
{
	OnExit(p);
	//check if the ammo and health is on max
	//then go to Backup or Help - previous phase might need 
	// savings in order to go back directly to Help
	Support* f = dynamic_cast<Support*>(p);
	if (f)
	{
		if (f->getHealth() == SMAX_HEALTH && f->getAmmo() == SMAX_AMMO)
			f->setCurrentState(new Backup());
	}
	
}

// exiting current state
void Restock::OnExit(Player* p)
{
	//not sure if there is a need for that
}
