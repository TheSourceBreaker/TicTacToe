#include "ShortCut.h"
#include "Turns.h"

int main()
{
	//-------------------------------------------------------------------------------
	Turns trn;

	int p1Input = 1;
	int p2Input = 2;

	int startupChoice = 0;
	int total = 0;
	int boardSize = 3;

	int *ptrp1Choice = &trn.p1Choice; //The player's decision during their turn.
	int *ptrp2Choice = &trn.p2Choice;

	bool *ptrp1Win = &trn.p1Win; //This becomes true for the winner.
	bool *ptrp2Win = &trn.p2Win;

	bool *ptrp1Turn = &trn.p1Turn; //This becomes true if it's their turn.
	bool *ptrp2Turn = &trn.p2Turn;

	//-------------------------------------------------------------------------------
	
	cout << " Welcome to Tic-Tac-Toe!\n What board size are you looking for?\n";
	cin >> boardSize;
	

	int** board = new int*[boardSize];

	cout << "Ok and which player wants to start first? (1? or 2?)\n\n";
	cin >> startupChoice;

	if (startupChoice == 1)//Choose which player will go first. Player1?
	{
		*ptrp1Turn = true;
		*ptrp2Turn = false;
	}
	else if (startupChoice == 2)//or Player2?
	{
		*ptrp1Turn = false;
		*ptrp2Turn = true;
	}

	for (int o = 0; o < boardSize; o++)//Board Instantiating Process-------------------------------
	{
		board[o] = new int[boardSize];

		for (int i = 0; i < boardSize; i++)
			board[o][i] = 0;
	}

	//-------------------------------------------------------------------------------

	while (*ptrp1Win == false || *ptrp2Win == false) //This will always be active until one of them becomes true.
	{
		if (*ptrp1Turn == true && *ptrp2Turn == false) //Player 1's Validation Statement
		{

			for (int p = 0; p < boardSize; p++)//Display the board-----------------------------
			{
				for (int y = 0; y < boardSize; y++)
					cout << " [" << board[p][y] << "]";

				cout << endl;
			}

			cout << " It's Player1's Turn!\n";
			
			while (true)
			{
				cin >> *ptrp1Choice;

				if (*ptrp1Choice > 0 && *ptrp1Choice <= (boardSize * boardSize)) //This checks to see if the input the player typed in isn't just random symbols.
					break;

				else //else go back through the loop and try again.
					cout << " That choice is invalid, try again" << endl;


			}
				Process(ptrp1Choice, board, boardSize, p1Input);//-----------------------------------


			
			*ptrp1Turn = false;
			*ptrp2Turn = true;
		}

		Victory(ptrp1Choice, board, boardSize, p1Input);


		if (*ptrp2Turn == true && *ptrp1Turn == false) //Player 2's Validation Statement
		{
			for (int p = 0; p < boardSize; p++) //Displays the board
			{
				for (int y = 0; y < boardSize; y++)
					cout << " [" << board[p][y] << "]";

				cout << endl;
			}

			cout << "It's Player2's Turn!\n";

			while (true)
			{
				cin >> *ptrp2Choice;

				if (*ptrp2Choice > 0 && *ptrp2Choice <= (boardSize * boardSize))
					break;

				else
					cout << " That choice is invalid, try again" << endl;
			}

			Process(ptrp2Choice, board, boardSize, p2Input);//-----------------------------------


			*ptrp1Turn = true;
		    *ptrp2Turn = false;
		}

		//Check Victory function here (player2)
	
	}

	// INCOMING PROBLEMS: Player Input, The Check-Victory function

	//Check to see if the players input is valid-------Input to see and implement what the player typed in-----------then Victory to see if they one or not.

	return 0;
}