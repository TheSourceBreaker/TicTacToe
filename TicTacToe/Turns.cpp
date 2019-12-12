#include "Turns.h"



void Process(int *playerChoice, int **board, int boardSize, int Input)
{
	/*if (board[(*playerChoice - 1) / boardSize][(*playerChoice - 1) % boardSize] == 1 || board[(*playerChoice - 1) / boardSize][(*playerChoice - 1) % boardSize] == 2)
	{
		cout << "processtest" << endl;
	}
	else
	{
	}*/
		board[(*playerChoice - 1) / boardSize][(*playerChoice - 1) % boardSize] = Input;
}

void Victory(int *playerChoice, int **board, int boardSize, int Input)
{
	int total = 0;
	for (int i = 0; i < boardSize; i++)
	{
		for (int o = 0; o < boardSize; o++)
		{
			if (board[i][o] == Input)
			{
				total++;
				//cout << "Test Victory";
			}
		}
	}

	for (int y = 0; y < boardSize; y++)
	{
		
		if (board[y][0] == Input)
		{
			total++;
			//cout << "Test Victory";
		}
		
	}

	for (int b = 0; b < boardSize; b++)
	{
		
		if (board[0][b] == Input)
		{
			total++;
			//cout << "Test Victory";
		}
		
	}
}
