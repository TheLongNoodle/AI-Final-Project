#pragma once
#include "State.h"

// Fire at nearby enemies

class Fire :
    public State
{
public:
	void OnEnter(Player* p);
	void Transition(Player* p);
	void OnExit(Player* p);
};

