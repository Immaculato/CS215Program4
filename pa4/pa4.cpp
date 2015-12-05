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

	Board test;
	test.PrintBoard();
	cout << test.WordOnBoard("AFL");
    system("pause");
    return 0;
}
