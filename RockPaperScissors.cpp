// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Teodulfo Espero
// BS Cloud and Systems Administration
// BS Software Development
// Western Governors University

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	//----------------------------------------------------------------------------------------
	//	define our vars

	string
		winner = "";

	char
		player01 = NULL,
		player02 = NULL,
		playagain = 'y';

	bool
		someonewon = false,
		validletters = false,
		continueplaying = true;

	//----------------------------------------------------------------------------------------
	//	start the game by asking the players r(ock) , p(aper), s(cissors)
	//	validate each player's input that we can only accept
	//		-	r(ock)
	//		-	p(aper)
	//		-	s(cissors)

	do {
		cout << "Rock, Paper, Scissors" << endl;
		cout << endl << endl;

		//----------------------------------------------------------------------------------------
		//	keep playing until someone wins
		while (!(someonewon)) {
			do {
				cout << "Player 1..... ";
				cin >> player01;
				player01 = tolower(player01);
				if (player01 == 'r' || player01 == 's' || player01 == 'p')
					validletters = true;
				else
					cout << "\t*** Invalid input." << endl;
			} while (!(validletters));

			validletters = false;

			do {
				cout << "Player 2..... ";
				cin >> player02;
				player02 = tolower(player02);
				if (player02 == 'r' || player02 == 's' || player02 == 'p')
					validletters = true;
				else
					cout << "\t*** Invalid input." << endl;
			} while (!(validletters));

			//----------------------------------------------------------------------------------------
			//	check if we have a draw then we no longer check for a winner
			//	and just skip into asking if the players would like another run at the game
			if (player01 == player02) {
				cout << "\t*** Looks like we have a draw. No one won this round." << endl;
				someonewon = true;
			}

			//----------------------------------------------------------------------------------------
			//	check if either player won
			else if (player01 == 'r' && player02 == 's')
				winner = "Player 01";
			else if (player01 == 's' && player02 == 'p')
				winner = "Player 01";
			else if (player01 == 'p' && player02 == 'r')
				winner = "Player 01";
			else if (player02 == 'r' && player01 == 's')
				winner = "Player 02";
			else if (player02 == 's' && player01 == 'p')
				winner = "Player 02";
			else if (player02 == 'p' && player01 == 'r')
				winner = "Player 02";
			if (winner.length() > 0) {
				someonewon = true;
				cout << "\t*** Congratulations. " << winner << " is the winner." << endl;
			}
		}
		//----------------------------------------------------------------------------------------
		//	ask if the players would like another game
		//	valid inputs can only be
		//		-	y(es)
		//		-	n(o)
		do {
			cout << endl << "Continue playing [y/n]?..... ";
			cin >> playagain;

			playagain = (tolower(playagain));
		} while (!(playagain == 'y' || playagain == 'n'));

		if (playagain == 'n')
			continueplaying = false;
		else {
			someonewon = false;
			winner = "";
			validletters = false;
			cout << endl << endl;
		}
	} while (continueplaying);
}

