#ifndef CELL_H
#define CELL_H

#include <iostream>
using namespace std;
class Grid;

enum State
{
	ALIVE,
	DEAD
};

class Cell {
private:	
	State state;
	int i, j;
	bool isAlive() const;
public:
	Cell();

	// Getter for cell current state
	State getState()const;

	// Setter for cell's current state
	void setState(State);

	// Setter for cell's current position on the grid
	void setPosition(int, int);

	// Toggles state of the cell
	void updateState();

	// count number of alive neighbours and return
	int neighbours(const Grid&);
	friend ostream& operator<<(ostream&, const Cell&);
};

#endif // !CELL_H