#include "Problem.h"

/*
void Problem::initializeGraphLibraries() {
	cout << "initializeGraphLibrariesStart" << endl;
	// return;
	vector<vector<int> > ids(L, vector<int>());
	libraryAdj.assign(L, vector<EdgeLibrary>());
	for(int i = 0; i < L; i++) {
		ids[i].resize( Libraries[i].N );
		for(int j = 0; j < Libraries[i].N; j++) {
			ids[i][j] = Libraries[i].IDs[j];
		}
		sort(ids[i].begin(), ids[i].end());
	}
	for(int i = 0; i < L; i++) {
		for(int j = i + 1; j < L; j++) if(i != j) {
			int szI = (int)ids[i].size();
			int szJ = (int)ids[j].size();
			int a = 0, b = 0;
			EdgeLibrary edge;
			edge.fromId = i;
			edge.toId = j;
			edge.sharedBooks = 0;
			while(a < szI && b < szJ) {
				if(ids[i][a] == ids[j][b]) {
					edge.sharedBooks++;
					a++;
					b++;
				}
				else if(ids[i][a] > ids[j][b]) {
					b++;
				}
				else if(ids[i][a] < ids[j][b]) {
					a++;
				}
			}
			edge.percentSharedBooks = 1.0 * edge.sharedBooks / ( 1.0 * ( szI + szJ ) );
			libraryEdges.push_back(edge);
			libraryAdj[edge.fromId].push_back(edge);
			swap(edge.fromId, edge.toId);
			libraryAdj[edge.fromId].push_back(edge);
		}
	}	
	cout << "libEdgeSize = " << libraryEdges.size() << endl;
}*/
