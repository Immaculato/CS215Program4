/* Tristan Basil
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * 12/6/2015
 *
 * Header file for WordList class.
 */

#ifndef WORDLIST_H
#define WORDLIST_H
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class WordList {
public:
	/* WordList() - default constructor for word list.
	 *
	 * Description: 
	 *   creates an empty vector of strings as a word list.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   WordList object with an empty vector of words inside.
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
	WordList();

	/* WordList(string filename) - constructor for word list which uses a string filename.
	 *
	 * Description: 
	 *   parses the specified file into a vector of strings in the wordlist object.
	 *
	 * Inputs:
	 *   string name of the file
	 *
	 * Outputs:
	 *   A wordlist object with data member vector of all words in the file.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Make sure all of the words are in caps, and that the list is in alphabetical order.
	 */
	WordList(string filename);

	/* bool WordInList(string word) - tells if word is in the list of words.
	 *
	 * Description: 
	 *   uses a recursive helper function to conduct a binary search to see if the word is in the list.
	 *
	 * Inputs:
	 *   string word you're checking.
	 *
	 * Outputs:
	 *   true if found, false if not.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   make sure you're checking an all-caps word.
	 */
	bool WordInList(string word);

	/* int size() - returns current size of the vector of loaded words.
	 *
	 * Description: 
	 *   returns int size of vector of loaded words.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   size of word vector.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   used in loading the game.
	 */
	int size();


private:
	/* bool BinarySearch(string word, int lower, int higher) - tells if word occurs in wordlist.
	 *
	 * Description: 
	 *   Uses a binary search to see if the word occurs in the wordlist.
	 *
	 * Inputs:
	 *   Initially, the string word, the beginning index of the vector, and the end index of the vector.
	 *
	 * Outputs:
	 *   true if found, false if not.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   uses binary search to find the word. used in WordInList().
	 */
	bool BinarySearch(string word, int lower, int higher);

	//vector of strings containing all the specified words.
	vector<string> words;

};

#endif
