#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Player {
	string name;
	int currentScore;
};
class TicTacToe
{
private:
	int board[3][3];
	int turn; // player1 == 1, player2 == 2
	int gameOver;
	void PlayGame();
	Player p1, p2, ptie;

public:
	TicTacToe();
	int choosePosition(int i);
	void togglePlayer();
	void WinCheck();
	void displayBoard();
	void resetGame();
	bool checkDraw();
	void displayScore();
	

};
/*****************************************************************************
* Initiate the players (including tie), board[][], within a do while loop
* that should execute until player chooses to exit.
*****************************************************************************/
TicTacToe::TicTacToe()
{
	cout << "\nEnter Player 1 name:";
	getline(cin, p1.name);
	p1.currentScore = 0;
	cout << "\nEnter Player 2 name:";
	cin.ignore();
	getline(cin, p2.name);
	p2.currentScore = 0;
	ptie.currentScore = 0;

	do {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				board[i][j] = 0;// 0 means empty
		turn = 1; // player1
		gameOver = 0;
		displayBoard();
		PlayGame();
		displayScore();
		resetGame();
	} while (!gameOver);
}
/*****************************************************************************
* function will be passed to the playgame() where user will be prompted to enter move
* the input will be validated and passed to this function to update board (which checks
* for winner/draw and is used to update board.)
* The input is process into x and y coordinates using some logic
* Validate input. Check, Switch Players, Update board.
* Return: 0 if move was made, otherwise return the value stored in the board position.
*****************************************************************************/
int TicTacToe::choosePosition(int i)
{
	int x = (i - 1) / 3;
	int y = ((i + 2) % 3);
	int returnVal = board[x][y];
	if (returnVal == 0)
	{
		board[x][y] = turn;
		WinCheck();
		if (!gameOver)
			togglePlayer();
	}
	else
		cout << "Invalid move, try again.\n";
	displayBoard();
	return returnVal;
}
/*****************************************************************************
*Toggles between players.
*****************************************************************************/
void TicTacToe::togglePlayer()
{
	if (turn == 1)
		turn = 2;
	else
		turn = 1;
}
/*****************************************************************************
* If one of the 8 possible winning combinations is achieved, the gameOver will 
* equate to the winning players number. Gameover of 0 indicates no winner or draw
* if as elements in board[][] are not 0;
*****************************************************************************/
void TicTacToe::WinCheck()
{
	if ((board[0][0] == turn) && (board[1][0] == turn) && (board[2][0] == turn))
		gameOver = turn;
	else
		if ((board[0][1] == turn) && (board[1][1] == turn) && (board[2][1] == turn))
			gameOver = turn;
		else
			if ((board[0][2] == turn) && (board[1][2] == turn) && (board[2][2] == turn))
				gameOver = turn;
			else
				if ((board[0][0] == turn) && (board[0][1] == turn) && (board[0][2] == turn))
					gameOver = turn;
				else
					if ((board[1][0] == turn) && (board[1][1] == turn) && (board[1][2] == turn))
						gameOver = turn;
					else
						if ((board[2][0] == turn) && (board[2][1] == turn) && (board[2][2] == turn))
							gameOver = turn;
						else
							if ((board[0][0] == turn) && (board[1][1] == turn) && (board[2][2] == turn))
								gameOver = turn;
							else
								if ((board[0][2] == turn) && (board[1][1] == turn) && (board[2][0] == turn))
									gameOver = turn;
}
/*****************************************************************************
* increments player scores when game is over. 
*****************************************************************************/
void TicTacToe::displayScore() {
	int tie = 0;
	if (gameOver == 1)
		p1.currentScore += 1;
	else if (gameOver == 2)
		p2.currentScore += 1;
	else
		ptie.currentScore += 1;

	cout << "\t\tPlayer 1 wins\t\t\tPlayer 2 Wins\t\t\tTie Games\n";
	cout << "\t\t-------------------------------------------------------------------------------\n";
	cout << "\t\t\t" << p1.currentScore << "\t\t\t\t" << p2.currentScore << "\t\t\t  " << ptie.currentScore << endl;

}
/*****************************************************************************
Checks to see if board has been changed from zero's. If all have been filled(picked)
the function returns a boolean false.
*****************************************************************************/
bool TicTacToe::checkDraw() {
	bool check;
	int count = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (board[i][j] > 0)
				count += 1;
		}
	if (count == 9)
		return false;
	else
		return true;

}

/*****************************************************************************
* Checks to see game has been won and if game is a draw. Both have work in tandum

*****************************************************************************/
void TicTacToe::PlayGame()
{
	int i;


	while (gameOver != turn && checkDraw()) {
		//DrawBoard();
		cout << "Player[" << turn << "] Please enter move: ";
		cin >> i;
		choosePosition(i);
	}

	if (gameOver != turn && !checkDraw())
		cout << "DRAW!!!" << endl;
	else
		cout << "Player[" << turn << "] Wins!" << endl;




}
/*****************************************************************************
* Asks user if they wish to continue the series. Sets board back to 0. Resets Gameover .
* if 2 new players, then the player scores are rest and then board is reset.
*****************************************************************************/
void TicTacToe::resetGame() {
	int set;
	//Display menu after each game
	cout << "1) Start a new match\n";
	cout << "2) Continue the current match (same two players)\n";
	cout << "3) Exit\n";
	cin >> set;
	while (set != 1 && set != 2 && set != 3) {
		cout << "Invalid input, option 1, 2, or 3: ";
		cin >> set;
	}
	switch (set) {
	case 1:
		p1.currentScore = 0;
		p2.currentScore = 0;
		ptie.currentScore = 0;
	case 2:
		gameOver = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				board[i][j] = 0;
		break;
	case 3:
		gameOver = 1;
		break;

	}
}
/*****************************************************************************
* Display the game board using ASCII characters.
*****************************************************************************/
void TicTacToe::displayBoard()
{
	int temp[9];
	int k = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 0)
				temp[k] = k + 49;
			else
			{
				if (board[i][j] == 1)
					temp[k] = 88;
				else
					temp[k] = 79;
			}
			k++;
		}
	cout << "+---+---+---+\n";
	cout << "| " << (char)temp[0] << " | " << (char)temp[1] << " | " << (char)temp[2] << " | \n";
	cout << "+---+---+---+\n";
	cout << "| " << (char)temp[3] << " | " << (char)temp[4] << " | " << (char)temp[5] << " | \n";
	cout << "+---+---+---+\n";
	cout << "| " << (char)temp[6] << " | " << (char)temp[7] << " | " << (char)temp[8] << " | \n";
	cout << "+---+---+---+\n";
}