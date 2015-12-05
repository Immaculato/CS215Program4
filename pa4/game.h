#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "wordlist.h"

using namespace std;

class Game {
public:
	//default constructor
	Game();
	//checks whether the game is over
	bool IsGameOver();
	//checks whether the word is legal. returns a 0 if not a word, 1 if not on board, and 2 if good.
	int IsWordLegal(string word);
	//takes a turn
	void TakeTurn();
	//prints that the game is over and some other useful stuff
	void GameOverManGameOver();

private:
	WordList ListOfWords;
	Board Gameboard;
	int score;
	int misses;
	vector<string> AlreadyUsedWords;

};

#endif
