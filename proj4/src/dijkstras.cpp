// dijkstras.cpp
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int nTiles, tileCost, nRows, nCols, sRow, sCol, eRow, eCol;
	char tileType;
	map<char, int> costs;
	vector<int> mapCosts; // Regular vector representing 2D vector
	vector<int> backLinks; // Stores index of nodes (use -1 instead of NULL)
	vector<int> distances; // Cost to go from start to node (-1 if unvisited)
	// Dev Note: May or may not need visited vector of bools
	multimap<int, int> paths; // Key = Distance from the starting node to the node; Val = the node (vect index) itself

	while(cin >> nTiles) {
		// Stores info of each tile type
		for(int i = 0; i < nTiles; i++) {
			cin >> tileType >> tileCost;
			costs.insert({tileType, tileCost});
		}

		// Reads in the map, stores as cost, and set up Dijkstras
		cin >> nRows >> nCols;
		for(int i = 0; i < nRows * nCols; i++) {
			cin >> tileType;
			tileCost = costs[tileType];
			mapCosts.push_back(tileCost);
			backLinks.push_back(-1);
			distances.push_back(-1);
		}
		
		// Read in runner's path info
		cin >> sRow >> sCol >> eRow >> eCol;

		// Dev Note: May or may not need an adjacency list/matrix to store edges before starting Dijkstras
		// Dev Note: Alternatively, can check for edges while processing nodes

		// For reference: (cRow = current row, cCol = current column)
		// Up = vect[(cRow - 1) * nCols + cCol], Down = vect[(cRow + 1) * nCols + cCol]
		// Left = vect[cRow * nCols + cCol - 1], Right = vect[cRow * nCols + cCol + 1]

		// Run Dijkstras
		// Set starting node to 0 and add it to multimap
		distances[sRow * nCols + sCol] = 0;
		paths.insert(pair<int, int>(0, sRow * nCols + sCol));
		// Dev Note: Start Dijkstras loop here. Need to research when loop terminates
	}
	return 0;
}

