#pragma once
#include "State.h"
class Fire :
    public State
{
public:
	void OnEnter(Player* p);
	void Transition(Player* p);
	void OnExit(Player* p);

};

