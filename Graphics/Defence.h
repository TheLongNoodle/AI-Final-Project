#pragma once
#include "State.h"

const double wx = -0.6;
const double wy = -0.3;
class Defence :
    public State
{   
	void OnEnter(Player* p);
	void Transition(Player* p);
	void OnExit(Player* p);
};

