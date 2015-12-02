#include "position.h"

Position::Position()
    : m_xcoord(0), m_ycoord(0)
{}

Position::Position(int xcoord, int ycoord)
    : m_xcoord(xcoord), m_ycoord(ycoord)
{}

int Position::x() const
{
    return m_xcoord;
}

int Position::y() const
{
    return m_ycoord;
}

void Position::setX(int xcoord)
{
    m_xcoord = xcoord;
}

void Position::setY(int ycoord)
{
    m_ycoord = ycoord;
}
