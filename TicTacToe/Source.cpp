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

	int *p1Choice = &trn.p1Choice; //The player's decision during their turn.
	int *p2Choice = &trn.p2Choice;

	bool *p1Win = &trn.p1Win; //This becomes true for the winner.
	bool *p2Win = &trn.p2Win;

	bool *p1Turn = &trn.p1Turn; //This becomes true if it's their turn.
	bool *p2Turn = &trn.p2Turn;

	//-------------------------------------------------------------------------------
	
	cout << " Welcome to Tic-Tac-Toe!\n What board size are you looking for?\n";
	cin >> boardSize;
	

	int** board = new int*[boardSize];

	cout << "Ok and which player wants to start first? (1? or 2?)\n\n";
	cin >> startupChoice;

	if (startupChoice == 1)//Choose which player will go first. Player1?
	{
		*p1Turn = true;
		*p2Turn = false;
	}
	else if (startupChoice == 2)//or Player2?
	{
		*p1Turn = false;
		*p2Turn = true;
	}

	for (int o = 0; o < boardSize; o++)//Board Instantiating Process-------------------------------
	{
		board[o] = new int[boardSize];

		for (int i = 0; i < boardSize; i++)
			board[o][i] = 0;
	}

	//-------------------------------------------------------------------------------

	while (*p1Win == false && *p2Win == false) //This will always be active until one of them becomes true.
	{
		if (*p1Turn == true && *p2Turn == false) //Player 1's Validation Statement
		{

			for (int p = 0; p < boardSize; p++)//Display the board
			{
				for (int y = 0; y < boardSize; y++)
					cout << " [" << board[p][y] << "]";

				cout << endl;
			}

			cout << " It's Player1's Turn!\n";
			
			while (true)
			{
				cin >> *p1Choice;

				if (*p1Choice > 0 && *p1Choice <= (boardSize * boardSize)) //This checks to see if the input the player typed in isn't just random symbols.
					break;
				else //else go back through the loop and try again.
					cout << " That choice is invalid, try again" << endl;
			}
			Process(p1Choice, board, boardSize, p1Input, p2Turn, p1Turn);
		}
		Victory(p1Choice, board, boardSize, p1Input, p1Win);


		if (*p1Win == false)//Checks if player 1 already won
		{
			if (*p2Turn == true && *p1Turn == false) //Player 2's Validation Statement
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
					cin >> *p2Choice;

					if (*p2Choice > 0 && *p2Choice <= (boardSize * boardSize)) //This checks to see if the input the player typed in isn't just random symbols.
						break;

					else
						cout << " That choice is invalid, try again" << endl;

				}
				Process(p2Choice, board, boardSize, p2Input, p1Turn, p2Turn);
			}
			Victory(p2Choice, board, boardSize, p2Input, p2Win);
		}
	}

	for (int p = 0; p < boardSize; p++) //Displays the board
	{
		for (int y = 0; y < boardSize; y++)
			cout << " [" << board[p][y] << "]";

		cout << endl;
	}

	if (*p1Win == true)
		cout << "Player 1 Wins" << endl;
	else if (*p2Win == true)
		cout << "Player 2 Wins" << endl;
	else 
		cout << "It's a Tie" << endl;


	while(true){}

	// INCOMING PROBLEMS: Check for already existing numbers in a slot (1 or 2 instead of 0 when receiving a new input)

	return 0;
}