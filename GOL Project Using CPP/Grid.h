#ifndef GRID_H
#define GRID_H

class Cell;;

class Grid {
	Cell** cells;
	int rows, cols;
	Grid* prevState;
	int noOfGeneration;
	Grid* nextGen;

	// Update current generation to next
	void updateGen();

	// Validates provided index
	bool isValidCell(int, int);

	// copy constructor for initializing nextGen with current
	Grid(const Grid&);
public:
	Grid(int, int);

	// Return readable Cell object at given positon
	const Cell& getCell(int, int) const;

	// Finds the next generation of the grid
	void nextGeneration();

	// Inputs cells that must be alive at Turn 0
	void getInitState();
	int getRowCount() const;
	int getColCount() const;
	
	// displays grid onto the screen in formatted manner
	void displayGrid() const;
	~Grid();
};

#endif // !GRID_H