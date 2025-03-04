#pragma once

const int MSZ = 100;

const int WALL = 0;
const int SPACE = 1;
const int START = 2;
const int TARGET = 3;
const int BLACK = 4;
const double PI = 3.14;
const double SECURITY_FACTOR = 0.001;

extern int tempMaze[MSZ][MSZ];
extern int maze[MSZ][MSZ];
extern double security_map[MSZ][MSZ];