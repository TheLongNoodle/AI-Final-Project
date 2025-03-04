#pragma once
#include "State.h"

// Help fighters in need

class Help :
	public State
{
public:
	void OnEnter(Player* p);
	void Transition(Player* p);
	void OnExit(Player* p);
};