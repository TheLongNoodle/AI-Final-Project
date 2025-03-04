#pragma once
#include "State.h"
class TreatmentAndReload :
    public State
{
	void OnEnter(Player* p);
	void Transition(Player* p);
	void OnExit(Player* p);
};

