#ifndef BOARD_H
#define BOARD_H

#include <list>
#include "position.h"
#include "letters.h"
#include <iostream>
#include <cstdlib>

using namespace std;

const int BOARD_SIZE = 4;

class Board {
public:
	//initialize board with random letters
	Board();
	//prints the board to the screen
	void PrintBoard();
	//checks if word occurs on the board
	bool WordOnBoard(string word);


  // TODO: your public methods here

private:
  // Return a list of all the positions adjacent to p, horizontally,
  // vertically, and diagonally.  Should NOT include positions that
  // are outside the board (x < 0, x > 3, y < 0, or y > 3).
  list<Position> adjacent(Position p) const;

  // TODO: recursive helper function for word search 
  bool RecursiveWordSearch(string word, Position currentposition);

  //helper function that finds the position of a character on the board. will throw an error if it cant find one.
  Position FindPosition(char character);

  //accesses the character at the specified position
  char AccessPosition(Position givenposition);


  // private data member
  char letters[BOARD_SIZE][BOARD_SIZE];



};

#endif

