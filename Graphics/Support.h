#pragma once
#include "Player.h"

class Support : public Player
{
public:
	Support(double r, double c, int coward, int team);
	void play();
	void show();
};