#ifndef WORDLIST_H
#define WORDLIST_H
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class WordList {
public:
	WordList();
	//finds the wordlist and parses it into the vector of words.
	WordList(string filename);
	//checks whether the word is in the list, via binary search. uses the helper function to recursively find it.
	bool WordInList(string word);
	//accessor that reports the size of the word list. used in loading game
	int size();


private:
	//helper function that recursively finds a word in the list.
	bool BinarySearch(string word, int lower, int higher);
	//vector of strings containing all the specified words.
	vector<string> words;

};

#endif
