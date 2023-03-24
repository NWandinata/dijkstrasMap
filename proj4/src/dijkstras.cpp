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

		// Run Dijkstras
		// Need adjacency list
	}
	return 0;
}

