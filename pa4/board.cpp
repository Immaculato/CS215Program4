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
	for (int i=0; i<BOARD_SIZE; i++)
	{
		for (int j=0; j<BOARD_SIZE; j++)
		{
			letters[i][j] = randomLetter();
		}
	}
}

//prints the board to the screen
void Board::PrintBoard()
{
	for (int y=0; y<BOARD_SIZE; y++)
	{
		cout << "+---+---+---+---+" << endl;
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
	Position currentposition;
	currentposition = FindPosition(word[0]);
	return RecursiveWordSearch(word, currentposition);
}

bool Board::RecursiveWordSearch(string word, Position currentposition)
{
	if (currentposition.x() == -1)
	{
		return false;
	}
	else if (currentposition.x() == FindPosition(word[word.size()-1]).x() &&
		currentposition.y() == FindPosition(word[word.size()-1]).y())
	{
		return true;
	}
	list<Position> adjacentpositions = adjacent(currentposition);
	list<Position>::iterator itindex;
	itindex = adjacentpositions.begin();
	while (itindex != adjacentpositions.end())
	{
		Position tempposition = *itindex;
		if (AccessPosition(tempposition) == word[1])
		{
			return RecursiveWordSearch(word.substr(1, word.size() - 1), tempposition);
		}
		itindex++;
	}
	return false;
}

Position Board::FindPosition(char character)
{
	for (int y=0; y<BOARD_SIZE; y++)
	{
		for (int x=0; x<BOARD_SIZE; x++)
		{
			if (letters[y][x] == character)
			{
				Position currentposition(x, y);
				return currentposition;
			}
		}
	}
	Position currentposition(-1, -1);
	return currentposition;
}

char Board::AccessPosition(Position givenposition)
{
	return letters[givenposition.y()][givenposition.x()];
}