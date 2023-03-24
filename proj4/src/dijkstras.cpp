// dijsktras.cpp
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	int nTiles, tileCost, nRows, nCols, sRow, sCol, eRow, eCol;
	char tileType;
	map<char, int> costs;

	while(cin >> nTiles) {
		// Stores info of each tile type
		for(int i = 0; i < nTiles; i++) {
			cin >> tileType >> tileCost;
			costs.insert({tileType, tileCost});
		}

		cin >> nRows >> nCols;
		// Read in tiles and store into container
		// Regular vector representing 2D vector?
		
		// Read in runner's path info
		cin >> sRow >> sCol >> eRow >> eCol;

		// Run Dijsktras
	}
	return 0;
}

