#pragma once
#include "State.h"

const double FOREST_X = 0.7;
const double FOREST_Y = 0.5;


class Attack :
    public State
{
public:
	void OnEnter(Player* p) ;
	void Transition(Player* p) ;
	void OnExit(Player* p) ;

};

