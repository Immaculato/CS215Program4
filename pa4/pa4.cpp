/* Tristan Basil
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * 12/6/2015
 *
 * Driver function for WordGrid game.
 */

#include <iostream>
#include <ctime>
#include "game.h"

using namespace std;

int main()
{
	srand(time(NULL)); //seed with the current time of the computer.

	Game Boggle;  //for the boggle game thing,
	while (!Boggle.IsGameOver())  //while the game isn't over,
	{
		Boggle.TakeTurn();  //keep taking turns until it is over.
	}
	Boggle.GameOverManGameOver();  //when it's over, output the endcard.
	return 1;
}
