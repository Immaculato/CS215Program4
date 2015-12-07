/* Tristan Basil
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * 12/6/2015
 *
 * Implementation of game class.
 */

#include "game.h"

Game::Game()
{
	cout << "WordGrid - CS 215 PA4" << endl;
	cout << "Bonus features implemented: none" << endl << "Loading wordlist.txt . . . ";
	ListOfWords = WordList("wordlist.txt");						//this is a loading message
	cout << "Found " << ListOfWords.size() << " words.\n\n";
	Board Gameboard;
	score = 0;
	misses = 0;
	AlreadyUsedWords.clear();   //make all data members in a starting state.
}

	//checks whether the game is over
bool Game::IsGameOver()
{
	if (misses == 5)    //if there are 5 recorded misses,
	{
		return true;   //the game is over.
	}
	return false;   //otherwise, it isnt.
}

	//checks whether the word is legal. -1 means it was already used, 0 means its not a word, 1 means it isnt on the
	//board, and 2 means its good!
int Game::IsWordLegal(string word)
{
	int i=0;
	while(i<AlreadyUsedWords.size())    //while the index isn't at the end of the used words,
	{
		if (word == AlreadyUsedWords[i])  //if the word was already used,
		{
			return -1;   //return -1 to indicate it.
		}
		i++;
	}
	if (!ListOfWords.WordInList(word))    //if the list of words does not contain the specified word,
	{
		return 0;  //return 0 to indicate it.
	}
	else if (!Gameboard.WordOnBoard(word))  //if the board does not contain the specified correct word,
	{
		return 1;  //return 1 to indicate it.
	}
	return 2;  //return 2 if everything checks out, and the word is legal.
}


void Game::TakeTurn()
{
	Gameboard.PrintBoard();
	cout << "Score: " << score << "   Misses: " << misses << "/5" << endl;  //output the current status of the game and the board
	cout << "Your words: ";
	for (int i=0; i<AlreadyUsedWords.size(); i++)  //for each already used word,
	{
		if (i==0)
		{
			cout << AlreadyUsedWords[i];  //if its the first word, dont put a comma first.
		}
		else
		{
			cout << ", " << AlreadyUsedWords[i];  //otherwise print them with a comma beforehand.
		}
	}
	cout << endl;
	
	cout << "\nEnter a word: ";   //get a word from the user and make it uppercase.
	string word;
	cin >> word;
	word = upperCase(word);

	if (word == "Q")  //if it was a q,
	{
		misses=5;     //set misses to 5 to indicate game is over, and exit the function.
		return;
	}
	
	if (IsWordLegal(word) == 2)   //if the word is legal,
	{
		score += (word.size() * word.size());   //give them the appropriate points, and
		AlreadyUsedWords.push_back(word);		//put the used word onto the already used words vector.
	}
	else if (IsWordLegal(word) == 1)	//if the word isnt on the board,
	{
		misses+=1;   //give a miss, and say so.
		cout << "I could not find that word on the board.\n\n";
	}
	else if (IsWordLegal(word) == 0)	//if the word can't be found in the dictionary,
	{
		misses+=1;  //give a miss, and say so.
		cout << "That isn't a real word.\n\n";
	}
	else    //if the word wasn't any of those cases,
	{
		misses+=1;   //give a miss, and say that it was already used (that's the only case left!)
		cout << "You have already used that word.\n\n";
	}
}

void Game::GameOverManGameOver()
{
	cout << "Game over!" << endl << "Your score was " << score << " points." << endl;  //cout info from the game.
	cout << "Your words: ";
	for (int i=0; i<AlreadyUsedWords.size(); i++)
	{
		if (i==0)
		{
			cout << AlreadyUsedWords[i];
		}
		else
		{
			cout << ", " << AlreadyUsedWords[i];
		}
	}
	cout << "\n\n";
	system("pause");  //pause so they can see it, then quit.
}