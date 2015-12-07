/* Tristan Basil
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * 12/6/2015
 *
 * Header file for game class.
 */

#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "wordlist.h"

using namespace std;

class Game {
public:
	/* Game() - Default constructor
	 *
	 * Description: 
	 *  default constructor for game.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   A fully-initialized game with board, a vector of words, 0 misses/score, and an empty vector of used words.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   None.
	 */
	Game();
	
	/* bool IsGameOver() - checks if the game is over
	 *
	 * Description: 
	 *  returns whether the game is over or not by checking the amount of misses.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   True is game is over, false otherwise.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Checks if there are 5 misses. If you want the game to end, set it to 5 misses.
	 */
	bool IsGameOver();
	
	/* int IsWordLegal() - checks if the word is legal.
	 *
	 * Description: 
	 *  checks if a word is legal using binary search to see if its a word, then another recursive function to
	 *  see if it occurs on the board.
	 *
	 * Inputs:
	 *   a string word.
	 *
	 * Outputs:
	 *   -1 means it was already used, 0 means it's not a word, 1 means it isnt on the board, 
	 *   and 2 means it's legal.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   None.
	 */
	int IsWordLegal(string word);
	
	/* void TakeTurn() - takes a turn.
	 *
	 * Description: 
	 *  takes a turn for the game.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Outputs the board, takes in a new word, checks if the new word works, updates misses/score, etc
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   None.
	 */
	void TakeTurn();

	/* void GameOverManGameOver() - outputs info relating to the game being over.
	 *
	 * Description: 
	 *  call it when the game is officially over.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Outputs the final score, words found
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   They're in the ventilation, man!!!
	 */
	void GameOverManGameOver();

private:
	//list of legal words
	WordList ListOfWords;
	//gameboard that is played on. different every time
	Board Gameboard;
	//current score. awarded n^2 points for n length word.
	int score;
	//amount of misses. 5 tolerated before game over.
	int misses;
	//contains the legal words already used by the user.
	vector<string> AlreadyUsedWords;

};

#endif
