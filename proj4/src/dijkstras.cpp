// dijkstras.cpp
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int nTiles, tileCost, nRows, nCols, sRow, sCol, eRow, eCol, index, up, down, left, right, row, col;
	char tileType;
	map<char, int> costs;
	vector<int> mapCosts; // Regular vector representing 2D vector
	vector<int> backLinks; // Stores index of nodes (use -1 instead of NULL)
	vector<int> distances; // Cost to go from start to node
	// Dev Note: May or may not need visited vector of bools
	vector<int> edges;
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
		while(!paths.empty()) {
			// Remove node from front of the multimap
			index = paths.begin()->second;
			paths.erase(paths.begin());

			// Check for connected nodes (-1 if doesn't exist)
			row = index / nCols;
			col = index % nCols;

			if(row == 0) up = -1;
			else up = index - nCols;

			if(row == nCols - 1) down = -1;
			else down = index + nCols;

			if(col == 0) left = -1;
			else left = index - 1;

			if(col == nCols - 1) right = -1;
			else right = index + 1;

			edges.push_back(up);
			edges.push_back(down);
			edges.push_back(left);
			edges.push_back(right);

			for(int i = 0; i < edges.size(); i++) {
				if(edges[i] == -1) continue;
			}
		}
		
		// Dev Note: After Dijkstras is finished, sum distance and use back links to get path
	}
	return 0;
}

