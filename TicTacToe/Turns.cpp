#include "Turns.h"



void Process(int *playerChoice, int **board, int boardSize, int Input, bool *flipToTrue, bool *flipToFalse)
{
	board[(*playerChoice - 1) / boardSize][(*playerChoice - 1) % boardSize] = Input;

	*flipToTrue = true;
	*flipToFalse = false;
}

void Victory(int *playerChoice, int **board, int boardSize, int Input, bool *playerWin)
{
	int total = 0;
	int win = 0;
	int t = (boardSize - 1);

	for (int i = 0; i < boardSize; i++) //This checks the left to right rows
	{
		for (int o = 0; o < boardSize; o++)
		{
			if (board[i][o] == Input)
				total++;
		}
		if (total == boardSize)
		{
			*playerWin = true;
			break;
		}
		else
			total = 0;
	}
	//--------------------------------

	for (int o = 0; o < boardSize; o++)//This checks the top to down rows
	{
		for (int i = 0; i < boardSize; i++)
		{
			if (board[i][o] == Input)
				total++;
		}
		if (total == boardSize)
		{
			*playerWin = true;
			break;
		}
		else
			total = 0;
	}
	//--------------------------------

	for (int y = 0; y < boardSize; y++) //This checks diagonally from the top left to bottom right
	{
		if (board[y][y] == Input)
		{
			total++;
		}
	}
		if (total == boardSize)
			*playerWin = true;
	else
			total = 0;
	//--------------------------------

	for (int b = 0; b < boardSize; b++) //This checks diagonally from the top right to bottom left
	{
		if (board[b][t] == Input)
		{
			total++;
		}
		t--;
	}
	if (total == boardSize)
		*playerWin = true;
	else
		total = 0;
	//--------------------------------
}
