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
	bool foundtheword = false;
	vector<Position*> positions;
	positions = FindPositions(word[0]);
	int index=0;
	while (index<positions.size() && foundtheword==false)
	{
		foundtheword = RecursiveWordSearch(word, *positions[index]);
		index++;
	}
	ClearPositions(positions);
	return foundtheword;
}

bool Board::RecursiveWordSearch(string word, Position currentposition)
{
	if (word.size() == 1)
	{
		return true;
	}
	list<Position> adjacentpositions = adjacent(currentposition);
	list<Position>::iterator itindex;
	itindex = adjacentpositions.begin();
	bool found = false;
	while (itindex != adjacentpositions.end())
	{
		Position tempposition = *itindex;
		if (AccessPosition(tempposition) == word[1] && !found)
		{
			found = RecursiveWordSearch(word.substr(1, word.size() - 1), tempposition);
		}
		itindex++;
	}
	if (!found)
	{
		return false;
	}
}

vector<Position*> Board::FindPositions(char character)
{
	vector<Position*> positions;
	for (int y=0; y<BOARD_SIZE; y++)
	{
		for (int x=0; x<BOARD_SIZE; x++)
		{
			if (letters[y][x] == character)
			{
				Position* foundposition = new Position(x, y);
				positions.push_back(foundposition);
			}
		}
	}
	return positions;
}

void Board::ClearPositions(vector<Position*> positions)
{
	for (int i=0; i<positions.size(); i++)
	{
		delete positions[i];
	}
}

char Board::AccessPosition(Position givenposition)
{
	return letters[givenposition.y()][givenposition.x()];
}