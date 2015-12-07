/* Tristan Basil
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * 12/6/2015
 *
 * Implementation for board class.
 */

#include "board.h"
using namespace std;

list<Position> Board::adjacent(Position p) const
{
	list <Position> adj;

	// add -1, 0, and 1 to the X and the Y coordinate.  Be careful not to
	// return p itself.
	for (int x = p.x() - 1; x <= p.x() + 1; x++)
		for (int y = p.y() - 1; y <= p.y() + 1; y++)
		{
			if (x == p.x() && y == p.y())
				continue;
			else if (x < 0 || x >= BOARD_SIZE)
				continue;
			else if (y < 0 || y >= BOARD_SIZE)
				continue;
			else
				adj.push_back(Position(x, y));
		}

		return adj;
}

Board::Board()
{
	for (int i=0; i<BOARD_SIZE; i++)					//for the size of the board lengthwise, then
	{
		for (int j=0; j<BOARD_SIZE; j++)				//heightwise,
		{
			letters[i][j] = randomLetter();				//put a random letter in each location.
		}
	}
}

//prints the board to the screen
void Board::PrintBoard()
{
	for (int y=0; y<BOARD_SIZE; y++)
	{
		cout << "+---+---+---+---+" << endl;			//looks ugly, but prints the board in a 4x4 grid.
		for (int x=0; x<BOARD_SIZE; x++)
		{
			cout << "| " << letters[y][x] << " ";
		}
		cout << "|" << endl;
	}
	cout << "+---+---+---+---+" << endl;
}

//checks if word occurs on the board
bool Board::WordOnBoard(string word)
{
	bool foundtheword = false;
	vector<Position*> positions;
	positions = FindPositions(word[0]);
	int index=0;
	while (index<positions.size() && foundtheword==false)		//while the index is still in range and the word
	{                                                           //still hasn't been found,
		foundtheword = RecursiveWordSearch(word, *positions[index]);  //do a recursive word search and store it to the variable.
		index++;
	}
	ClearPositions(positions);   //make sure that the vector of positions has its allocated memory freed, and
	return foundtheword;         //return if the word was found in any of its possible starting locations.
}

bool Board::RecursiveWordSearch(string word, Position currentposition)
{
	if (word.size() == 1)    //base case: if the word is size 1,
	{
		return true;		//it's been found.
	}
	list<Position> adjacentpositions = adjacent(currentposition);
	list<Position>::iterator itindex;
	itindex = adjacentpositions.begin();
	bool found = false;
	while (itindex != adjacentpositions.end())   //while we arent at the end of the list,
	{
		Position tempposition = *itindex;
		if (AccessPosition(tempposition) == word[1] && !found)   //if the current position iteration contains the next character
		{                                                        //in the word,
			found = RecursiveWordSearch(word.substr(1, word.size() - 1), tempposition);  //loop again with the string without
		}                                                                                //the first character, and the iteration
																						 //position is the new current.
		itindex++;
	}
	if (!found)  //if after all the looping, the word STILL hasn't been found,
	{
		return false;  //return false.
	}
}

vector<Position*> Board::FindPositions(char character)
{
	vector<Position*> positions;
	for (int y=0; y<BOARD_SIZE; y++)
	{
		for (int x=0; x<BOARD_SIZE; x++)		//for each position on the board,
		{
			if (letters[y][x] == character)		//if the character at that position is the same as the specified character,
			{
				Position* foundposition = new Position(x, y);  //make a new position with those coordinates, and
				positions.push_back(foundposition);			   //put it onto the list.
			}
		}
	}
	return positions;
}

void Board::ClearPositions(vector<Position*> positions)
{
	for (int i=0; i<positions.size(); i++)    //for each position in the vector,
	{
		delete positions[i];				  //free up the memory.
	}
}

char Board::AccessPosition(Position givenposition)
{
	return letters[givenposition.y()][givenposition.x()];   //this accesses the letter at a given position.
}