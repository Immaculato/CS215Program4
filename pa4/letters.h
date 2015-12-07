/* Tristan Basil
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * 12/6/2015
 *
 * Header file for letters helper functions.
 */

#ifndef LETTERS_H
#define LETTERS_H

#include <string>
using namespace std;

/* char randomLetter() - return a random letter weighed according to english frequency.
	 *
	 * Description: 
	 *  returns a weighted random english letter.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   A random letter in english, weighted with frequency.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   I didn't write this or change it. I'm not sure the frequencies are 100% correct
	 */
char randomLetter();

/* string upperCase(string input) - converts a string to uppercase
	 *
	 * Description: 
	 *  converts a string to all uppercase characters.
	 *
	 * Inputs:
	 *   a string to capitalize.
	 *
	 * Outputs:
	 *   the capitalized version of the string.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   I didn't write this or change it.
	 */
string upperCase(string input);

#endif

