#include "Grid.h"
#include<iostream>
using namespace std;

int main() {
	int n, m, turns;
	cout << "Enter dimenstions of grid [N M]: ";
	cin >> n >> m;

	cout << "Enter number of turns: ";
	cin >> turns;

	Grid grid(n, m);
	grid.getInitState();

	for(int i=0;i<turns;i++) {
		cout << endl << "Turn " << i << ":" << endl;
		grid.nextGeneration();
		grid.displayGrid();
	}
	return 0;
}