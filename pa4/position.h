#ifndef POSITION_H
#define POSITION_H

// Class representing a position on a two-dimensional board.
// Stores an x and y coordinate, with methods to return and
// set each coordinate, and a method to test whether the
// position falls within a given width and height.
class Position
{
public:
    // Create a Position object for the origin (0, 0).
    Position();

    // Create a Position object for the position (xcoord, ycoord).
    Position(int xcoord, int yoord);

    // Getters and setters for x and y coordinates.
    int x() const;
    int y() const;
    void setX(int xcoord);
    void setY(int ycoord);
private:
    int m_xcoord;
    int m_ycoord;
};

#endif
