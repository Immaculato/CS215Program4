#include "wordlist.h"
#include <fstream>
#include <string>

WordList::WordList()
{
	words.clear();
}

WordList::WordList(string filename)
{
	ifstream infile;				//attempt to open the file
	infile.open(filename.c_str());

	if (infile.fail() == true) //if the file fails to open,
	{

		throw runtime_error("Error: Cannot open the file."); //throw a runtime error!
	}

	string line;
	while (getline(infile, line)) //while the file is still supplying valid lines,
	{
		words.push_back(line); //push back the pointer to the derived object to the array
	}
}

//checks whether the word is in the list, via binary search. uses the helper function to recursively find it.
bool WordList::WordInList(string word)
{
	if (BinarySearch(word, 0, words.size()-1))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//helper function that recursively finds a word in the list.
bool WordList::BinarySearch(string word, int lower, int higher)
{
	// test if array is empty
	if (higher < lower)
		// set is empty, so return value showing not found
			return false;
	else
	{
		// calculate midpoint to cut set in half
		int middle = ((higher + lower)/2);

		if (words[middle] > word)
		{
			return BinarySearch(word, lower, middle-1);
		}
		else if (words[middle] < word)
		{
			return BinarySearch(word, middle+1, higher);
		}
		else
		{
			return true;
		}
	}
}

int WordList::size()
{
	return words.size();
}
//vector of strings containing all the specified words.
//vector<string> words;