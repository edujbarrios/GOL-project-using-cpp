#include"Grid.h"
#include"Cell.h"


Grid::Grid(int n, int m) {
	rows = n;
	cols = m;
	noOfGeneration = 0;
	cells = new Cell * [rows+2];
	nextGen = nullptr;

	// creating array of Cells on heap
	for (int i = 0; i < rows+2; i++) {
		cells[i] = new Cell[cols+2];
		for (int j = 0; j < cols+2; j++) {
			// sets position of cells
			cells[i][j].setPosition(i, j);
		}
	}
}
void Grid::updateGen()
{
	if (cells) {
		for (int i = 0; i < rows+2; i++) {
			delete[] cells[i];
		}
	}
	delete[] cells;
	cells = nextGen->cells;
	noOfGeneration++;
}
bool Grid::isValidCell(int i, int j)
{
	return i>0 && i<=rows && j>0 && j<=cols;
}
Grid::Grid(const Grid& ref)
{
	rows = ref.rows;
	cols = ref.cols;
	noOfGeneration = 0;
	cells = new Cell * [rows + 2];
	nextGen = nullptr;
	for (int i = 0; i < rows + 2; i++) {
		cells[i] = new Cell[cols + 2];
		for (int j = 0; j < cols + 2; j++) {
			cells[i][j].setPosition(i, j);
			if (ref.cells[i][j].getState() == ALIVE)
				cells[i][j].updateState();
		}
	}

}
const Cell& Grid::getCell(int i, int j) const {
	if(i>=0 && i<rows+2 && j>=0 && j<cols+2)
		return cells[i][j];
	throw new out_of_range("Invalid Index");
}
void Grid::nextGeneration() {
	if (nextGen) {
		updateGen();
	}
	nextGen = new Grid(*this);
	// Loop through every cell
	for (int l = 1; l <= rows; l++)
	{
		for (int m = 1; m <=cols; m++)
		{
			// finding no Of Neighbours
			// that are alive
			int aliveNeighbours = cells[l][m].neighbours(*this);

			// updating there states based on the game rules
			if (aliveNeighbours == 3 && cells[l][m].getState() == DEAD) {
				nextGen->cells[l][m].updateState();
			}
			else if (aliveNeighbours != 2 && aliveNeighbours != 3 && cells[l][m].getState() == ALIVE) {
				nextGen->cells[l][m].updateState();
			}
		}
	}
}

void Grid::getInitState()
{
	// do nothing if no of generation is not 0 
	if (noOfGeneration != 0)
		return;

	int x = 0, y = 0;
	cout << "====== Enter Inititally Alive Cells ======\n";
	cout << "Enter positions of cells that must be alive at turn 0\nInput must be in range (1 to N) or (1 to M), Pattern [i j] i.e; 2 3\n";
	
	// Keeps getting indexes of alive cells until -1 -1 is entered
	while (x != -1 || y != -1) {
		cout << "Enter position, [-1 -1] to exit: ";
		cin >> x >> y;
		if (isValidCell(x, y)) {
			cells[x][y].setState(ALIVE);
		}
		else {
			cout << "index must be in range (1 to N) or (1 to M)\n";
		}
	}
}

int Grid::getRowCount() const
{
	return rows;
}

int Grid::getColCount() const
{
	return cols;
}

void Grid::displayGrid() const
{

	for (int r = 0; r <= cols + 2; r++)
		cout << "--";
	cout << endl;
	for (int i = 0; i < rows + 2; i++) {
		cout << "|";
		for (int j = 0; j < cols + 2; j++) {
			cout << cells[i][j] << ' ';
		}
		cout << "|";
		cout << endl;
	}
	for (int r = 0; r <= cols + 2; r++)
		cout << "--";
}

Grid::~Grid()
{
	// free up the heap memory
	if (cells) {
		for (int i = 0; i < rows; i++) {
			delete[] cells[i];
		}
	}
	delete nextGen;
	delete [] cells;
}

