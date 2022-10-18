#include "Cell.h"
#include "Grid.h"

Cell::Cell(){
	this->state = DEAD;
	this->i = -1;
	this->j = -1;
}

bool Cell::isAlive() const
{
	return state==ALIVE;
}

State Cell::getState()const {
	return state;
}

int Cell::neighbours(const Grid& grid) {
	int aliveCount = 0;
	int rows = grid.getRowCount();
	int cols = grid.getColCount();
	for (int m = i - 1; m <= i + 1; m++) {
		for (int n = j - 1; n <= j + 1; n++) {
			if (grid.getCell(m, n).isAlive()) {
				aliveCount++;
			}
		}
	}
	return aliveCount - 1;
	/*if (i - 1 >= 0)
	{
		if (j - 1 >= 0 && grid.getCell(i - 1, j - 1).isAlive()) {
			aliveCount++;
		}
		if (grid.getCell(i - 1, j).isAlive()) {
			aliveCount++;
		}
		if (j + 1 <= cols && grid.getCell(i - 1, j + 1).isAlive()) {
			aliveCount++;
		}
	}
	if (j - 1 >= 0 && grid.getCell(i, j - 1).isAlive()) {
		aliveCount++;
	}
	if (j + 1 <= cols && grid.getCell(i, j + 1).isAlive()) {
		aliveCount++;
	}
	if (i + 1 <= rows)
	{
		if (j - 1 >= 0 && grid.getCell(i + 1, j - 1).isAlive()) {
			aliveCount++;
		}
		if (grid.getCell(i + 1, j).isAlive()) {
			aliveCount++;
		}
		if (j + 1 <= cols && grid.getCell(i + 1, j + 1).isAlive()) {
			aliveCount++;
		}
	}

	return aliveCount;*/
}

void Cell::setState(State st) {
	state = st;
}
void Cell::setPosition(int r, int c)
{
	this->i = r;
	this->j = c;
}
void Cell::updateState() {
	state == ALIVE ? state = DEAD : state = ALIVE;
}

ostream& operator<<(ostream& out, const Cell& cell)
{
	cell.state == ALIVE ? out << 'X' : out << ' ';
	return out;
}
