/* Tristan Basil
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * 12/6/2015
 *
 * Header file for position class.
 */

#ifndef POSITION_H
#define POSITION_H

// Class representing a position on a two-dimensional board.
// Stores an x and y coordinate, with methods to return and
// set each coordinate, and a method to test whether the
// position falls within a given width and height.
class Position
{
public:
    /* Position() - default constructor for postion class.
	 *
	 * Description: 
	 *   creates a position at x=0 y=0.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   a position at x=0 y=0.
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
    Position();

     /* Position(int xcoord, int ycoord) - constructor for postion class.
	 *
	 * Description: 
	 *   creates a position at specified x and y.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   a position at specified x and y.
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
    Position(int xcoord, int yoord);

    /* int x() const and int y() const - accessors for x and y coordinates, respectively.
	 *
	 * Description: 
	 *   return x and y of position, respectively.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   the coordinates of the position.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   I didn't write theses or change them. applies to following 2 functions.
	 */
    int x() const;
    int y() const;

	/* void setX() and void setY() - setters for x and y coordinates, respectively.
	 *
	 * Description: 
	 *   setters for x and y of position, respectively.
	 *
	 * Inputs:
	 *   Sets x and y positions to specified coordinates.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   sets x and y positions to specified coordinates.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   I didn't write theses or change them. applies to following 2 functions.
	 */
    void setX(int xcoord);
    void setY(int ycoord);
private:
	//contains x coordinate of the position.
    int m_xcoord;
	//contains y coordinate of the position.
    int m_ycoord;
};

#endif
