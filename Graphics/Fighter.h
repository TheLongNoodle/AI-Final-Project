#pragma once
#include "Player.h"

class Fighter : public Player
{
public:
	Fighter(double r, double c, int coward, int team);
	void play();
	void show();
};