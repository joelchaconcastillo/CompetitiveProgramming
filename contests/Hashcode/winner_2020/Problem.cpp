/********************************************************************************
  Authors: Carlos Segura, Emmanuel Romero Ruíz, Gabriel Tadeo Vazquez Ballesteros 
	and Mario Guzman Silverio
*********************************************************************************/

#include "Problem.h"

//Load instances and calculate structures to fast access to information
Problem::Problem(const string &fileName){
	ifstream ifs(fileName, ifstream::in);
	if (!ifs.is_open()){
		cerr << "Error - Instance file " << fileName << " could not be opened" << endl;
		exit(-1);
	}
	//Num. books, Num. Libraries, Period D
	ifs >> B >> L >> D;
	S.resize(B);
	maxBookValue = 0;
	for(int i = 0; i < B; i++){
		ifs >> S[i];
		maxBookValue = max(maxBookValue, S[i]);
	}
	libraries.resize(L);
	librariesToBook.resize(L);
	book2library.assign(B, vector<int>());

	//Read libraries
	for(int i=0; i<L;i++){
		int N; 
		ifs >> N >> libraries[i].T >> libraries[i].M;//Num. books, Sign-up time
		libraries[i].IDs.resize(N); 
		for(int j=0;j<N;j++){
			ifs >> libraries[i].IDs[j];
			book2library[libraries[i].IDs[j]].push_back(i);
			librariesToBook[i].push_back(libraries[i].IDs[j]);
		}
		//Sort the books in the library by score in decreasing way
		//TODO: Is this needed? If so explain why
		vector < pair <int, int> > s_b;//cost-book
		for (int j = 0; j < libraries[i].IDs.size(); j++){
			s_b.push_back(make_pair(S[libraries[i].IDs[j]], libraries[i].IDs[j]));
		}
		sort(s_b.begin(), s_b.end());
		reverse(s_b.begin(), s_b.end());
		for (int j = 0; j < libraries[i].IDs.size(); j++){
			libraries[i].IDs[j] = s_b[j].second;
		}
	}
	ifs.close();
}
