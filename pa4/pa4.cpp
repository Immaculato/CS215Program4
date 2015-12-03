/* Name
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * Date
 *
 * Driver program for WordGrid game.
 */ 


#include <iostream>
#include "game.h"
#include "wordlist.h"

using namespace std;

int main()
{
	WordList words;
	words = WordList("wordlist.txt");
	cout << words.WordInList("TEST");


    system("pause");
    return 0;
}
