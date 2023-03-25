// dijkstras.cpp
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int nTiles, tileCost, nRows, nCols, sRow, sCol, eRow, eCol, index, up, down, left, right, row, col, edgeIndex, dist;
	char tileType;
	map<char, int> costs;
	vector<int> mapCosts; // Regular vector representing 2D vector
	vector<int> backLinks; // Stores index of nodes (use -1 instead of NULL)
	vector<int> distances; // Cost to go from start to node (-1 if unvisited)
	vector<int> edges;
	vector<int> finalPath;
	multimap<int, int> paths; // Key = Distance from the starting node to the node; Val = the node (vect index) itself

	cin >> nTiles;
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

		// Process all connected nodes
		dist = distances[index] + mapCosts[index];
		for(int i = 0; i < edges.size(); i++) {
			edgeIndex = edges[i];
			if(edgeIndex == -1) continue;

			// Connected node is unvisited or its distance is shorter
			if(distances[edgeIndex] == -1 || distances[edgeIndex] > dist) {
				// Remove node from multimap if already there (may need iterators)
				//typedef multimap<int, int>::iterator iterator;
				//pair<iterator, iterator> iterpair = mymap.equal_range(dist);

				// Updates distance and back-link
				distances[edgeIndex] = dist;
				backLinks[edgeIndex] = index;
				paths.insert(pair<int, int>(dist, edgeIndex));
			}
		}

		edges.clear();
	}
	
	// Dev Note: After Dijkstras is finished, use back links to get path
	// Total obtained through distances vector
	finalPath.push_back(eRow * nCols + eCol);
	index = backLinks[eRow * nCols + eCol];

	while(index != -1) {
		finalPath.push_back(index);
		index = backLinks[index];
	}

	// Print shortest path and its distance
	cout << distances[eRow * nCols + eCol] << endl;
	for(int i = finalPath.size() - 1; i >= 0; i--) {
		index = finalPath[i];
		row = index / nCols;
		col = index % nCols;
		cout << row << " " << col << endl;
	}
	return 0;
}

