#pragma once
#include "ShortCut.h"

struct Turns
{
	int p1Choice;
	int p2Choice;

	bool p1Win = false;
	bool p2Win = false;

	bool p1Turn = true;
	bool p2Turn = false;
};

void Process(int *playerChoice, int **board, int boardSize, int Input, bool *flipToTrue, bool *flipToFalse);
void Victory(int *playerChoice, int **board, int boardSize, int Input, bool *playerWin);
