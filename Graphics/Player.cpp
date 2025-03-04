#include "Player.h"
#include "Grenade.h"
#include "glut.h"

Player::Player(int xx, int yy, double a, double h, int cow, int t, State* s)
{
	x = xx;
	y = yy;
	ammo = a;
	health = h;
	team = t;
	cowardnessFactor = cow;
	pCurrentState = s;
}

void Player::doSomething()
{
}

bool Player::checkNeighbour(int row, int col, Cell* pCurrent)
{
	if ((row == targetY) && (col == targetX))
	{
		Cell* pPrev = pCurrent;
		while (pCurrent->getParent() != nullptr)
		{
			pPrev = pCurrent;
			pCurrent = pCurrent->getParent();
		}
		setX(pPrev->getCol());
		setY(pPrev->getRow());
		return true;
	}
	else
	{
		Cell* pc = new Cell(row, col, targetY, targetX, pCurrent->getG() + 1 + security_map[row][col], pCurrent);
		pq.push(pc);
	}
	return false;
}

void Player::AStarTarget()
{
	// clear pq
	while (!pq.empty())
		pq.pop();
	GenerateSecurityMap();
	// setup tempMaze
	int tempMaze[MSZ][MSZ] = { 0 };
	int curr;
	for (int i = 0; i < MSZ; i++)
		for (int j = 0; j < MSZ; j++)
		{
			curr = maze[i][j];
			if (curr != WALL)
			{
				tempMaze[i][j] = SPACE;
			}
			else
				tempMaze[i][j] = WALL;
		}

	tempMaze[y][x] = START;
	tempMaze[targetY][targetX] = TARGET;

	bool runAStar = true;
	pq.push(new Cell(y, x, targetY, targetX, 0, nullptr));
	Cell* pCurrent;
	int row, col;
	while (runAStar)
	{
		if (pq.empty())
		{
			runAStar = false;
			return;
		}
		else // grays is not empty
		{
			pCurrent = pq.top();
			pq.pop(); // extract the first element from grays

			// 1. paint pCurrent black
			row = pCurrent->getRow();
			col = pCurrent->getCol();
			if (tempMaze[row][col] != START)
				tempMaze[row][col] = BLACK;
			// 2. Check all neighbors of pCurrent

			// go up
			if (tempMaze[row + 1][col] == SPACE || tempMaze[row + 1][col] == TARGET)
			{
				if (checkNeighbour(row + 1, col, pCurrent))
				{
					runAStar = false;
					return;
				}
			}
			// go down
			if (tempMaze[row - 1][col] == SPACE || tempMaze[row - 1][col] == TARGET)
			{
				if (checkNeighbour(row - 1, col, pCurrent))
				{
					runAStar = false;
					return;
				}
			}
			// go left
			if (tempMaze[row][col - 1] == SPACE || tempMaze[row][col - 1] == TARGET)
			{
				if (checkNeighbour(row, col - 1, pCurrent))
				{
					runAStar = false;
					return;
				}
			}
			// go right
			if (tempMaze[row][col + 1] == SPACE || tempMaze[row][col + 1] == TARGET)
			{
				if (checkNeighbour(row, col + 1, pCurrent))
				{
					runAStar = false;
					return;
				}
			}
		}
	}
}

void Player::show(int xx, int yy)
{
}

void Player::GenerateSecurityMap()
{
	int numSimulations = 1000;

	for (int i = 0; i < numSimulations; i++)
	{
		Grenade* g = new Grenade(rand() % MSZ, rand() % MSZ, 0);
		g->SimulateExplosion(maze, security_map);
	}
	for (Player* p : players)
	{
		if(p->getTeam() != team)
			for (int i = 0; i < numSimulations; i++)
			{
				Grenade* g = new Grenade(p->getX(), p->getY(), 0);
			}
	}
}
