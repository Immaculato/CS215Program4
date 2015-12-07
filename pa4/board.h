/* Tristan Basil
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * 12/6/2015
 *
 * Header file for board class.
 */

#ifndef BOARD_H
#define BOARD_H

#include <list>
#include "position.h"
#include "letters.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

const int BOARD_SIZE = 4;

class Board {
public:

	/* Board() - Default constructor for board class.
	 *
	 * Description: 
	 *  Default constructor for board class. Randomizes the board by default.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   A 4x4 board variable containing a randomized layout.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Uses randomLetter() to use the relative frequencies of letters in english.
	 */
	Board();

	/* void PrintBoard() - Prints the board to standard output.
	 *
	 * Description: 
	 *  Prints the board to cout.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Prints the board to standard output.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   None.
	 */
	void PrintBoard();
	
	/* void PrintBoard() - Checks if the word occurs on the board.
	 *
	 * Description: 
	 *  Uses a recursive helper to find if the word occurs on the board.
	 *
	 * Inputs:
	 *   A string word to find on the board.
	 *
	 * Outputs:
	 *   True if present, false if not.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Uses a recursive helper to accomplish this. Note that it will find words that arent real - must
	 *   verify before using this function that it is a real word.
	 */
	bool WordOnBoard(string word);

private:
  
	/* list<Position> adjacent(Position p) const - return list of adjacent positions to a specified position.
	 *
	 * Description: 
	 *  finds horizontally, vertically, and diagonally adjacent positions to another position.
	 *
	 * Inputs:
	 *   Position to find adjacent positions from.
	 *
	 * Outputs:
	 *   A vector of adjacent positions.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   I didn't write this.
	 */
  list<Position> adjacent(Position p) const;

  /* void RecursiveWordSearch(string word, Position currentposition) - Checks if the word occurs on the board 
     *							recursively, using the word and the position of its first letter on the board.
	 *
	 * Description: 
	 *  Uses the word and the position of its first letter to find it on the board.
	 *
	 * Inputs:
	 *   A string word and a Position of the first letter.
	 *
	 * Outputs:
	 *   True if present, false if not.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   This is is the recursive helper used in WordOnBoard.
	 */ 
  bool RecursiveWordSearch(string word, Position currentposition);

  /* void FindPositions(char character) - Finds where a character is on a board.
	 *
	 * Description: 
	 *  Finds the positions of a character on the board, if it appears at all.
	 *
	 * Inputs:
	 *   A character to find Positions of.
	 *
	 * Outputs:
	 *   A vector of pointers to positions.
	 *
	 * Side-effects:
	 *   Uses heap memory to store pointers to positions.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Make sure you use these to find a word on the board using the recursive function.
	 */
  vector<Position*> FindPositions(char character);

  /* void ClearPositions - Frees the memory allocated in a Position* vector.
	 *
	 * Description: 
	 *  Deletes all the dynamically allocated memory used in FindPositions function.
	 *
	 * Inputs:
	 *   A vector of pointers to positions to clear memory form.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Frees memory allocated to position pointers.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Make sure you call this after using FindPositions, otherwise you will have a memory leak.
	 */
  void ClearPositions(vector<Position*> positions);

  /* void AccessPosition(Position givenposition) - returns the character at a given position.
	 *
	 * Description: 
	 *  Returns the character at a given position.
	 *
	 * Inputs:
	 *   a position to find a character from.
	 *
	 * Outputs:
	 *   the character at the position.
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
  char AccessPosition(Position givenposition);


  // 2 dimensional array of letters used on the board.
  char letters[BOARD_SIZE][BOARD_SIZE];



};

#endif

