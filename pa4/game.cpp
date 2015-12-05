#include "game.h"

Game::Game()
{
	cout << "WordGrid - CS 215 PA4" << endl;
	cout << "Bonus features implemented: none" << endl << "Loading wordlist.txt . . . ";
	ListOfWords = WordList("wordlist.txt");
	cout << "Found " << ListOfWords.size() << " words.\n\n";
	Board Gameboard;
	score = 0;
	misses = 0;
	AlreadyUsedWords.clear();
}

	//checks whether the game is over
bool Game::IsGameOver()
{
	if (misses == 5)
	{
		return true;
	}
	return false;
}

	//checks whether the word is legal. -1 means it was already used, 0 means its not a word, 1 means it isnt on the
	//board, and 2 means its good!
int Game::IsWordLegal(string word)
{
	int i=0;
	while(i<AlreadyUsedWords.size())
	{
		if (word == AlreadyUsedWords[i])
		{
			return -1;
		}
		i++;
	}
	if (!ListOfWords.WordInList(word))
	{
		return 0;
	}
	else if (!Gameboard.WordOnBoard(word))
	{
		return 1;
	}
	return 2;
}

	//takes a turn
void Game::TakeTurn()
{
	Gameboard.PrintBoard();
	cout << "Score: " << score << "   Misses: " << misses << "/5" << endl;
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
	cout << endl;
	
	cout << "\nEnter a word: ";
	string word;
	cin >> word;
	word = upperCase(word);
	
	if (IsWordLegal(word) == 2)
	{
		score += (word.size() * word.size());
		AlreadyUsedWords.push_back(word);
	}
	else if (IsWordLegal(word) == 1)
	{
		misses+=1;
		cout << "I could not find that word on the board.\n\n";
	}
	else if (IsWordLegal(word) == 0)
	{
		misses+=1;
		cout << "That isn't a real word.\n\n";
	}
	else
	{
		misses+=1;
		cout << "You have already used that word.\n\n";
	}
}

	//prints that the game is over and some other useful stuff
void Game::GameOverManGameOver()
{
	cout << "Game over!" << endl << "Your score was " << score << " points." << endl;
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
	system("pause");
}
/*
WordList ListOfWords;
Board Gameboard;
int score;
int misses;
vector<string> AlreadyUsedWords;
*/
