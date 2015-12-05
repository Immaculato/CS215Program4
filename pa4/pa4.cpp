/* Name
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * Date
 *
 * Driver program for WordGrid game.
 */ 


#include <iostream>
#include "game.h"

using namespace std;

int main()
{
	/*
	WordList words;
	words = WordList("wordlist.txt");
	system("pause");
	cout << words.WordInList("LEFT");
	*/

	Game Boggle;
	while (!Boggle.IsGameOver())
	{
		Boggle.TakeTurn();
	}
	Boggle.GameOverManGameOver();
}
