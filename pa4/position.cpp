/* Tristan Basil
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * 12/6/2015
 *
 * Implementation for position class.
 */

#include "position.h"

Position::Position()
    : m_xcoord(0), m_ycoord(0)   //intialize with x=0 y=0
{}

Position::Position(int xcoord, int ycoord)    //initialize with x=specified x, y=specified y
    : m_xcoord(xcoord), m_ycoord(ycoord)
{}

int Position::x() const
{
    return m_xcoord;  //return x
}

int Position::y() const
{
    return m_ycoord;	//return y
}

void Position::setX(int xcoord)
{
    m_xcoord = xcoord;   //set x
}

void Position::setY(int ycoord)
{
    m_ycoord = ycoord;    //set y
}
