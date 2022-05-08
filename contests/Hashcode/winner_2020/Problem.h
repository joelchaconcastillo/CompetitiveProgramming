/********************************************************************************
  Authors: Carlos Segura, Emmanuel Romero Ruíz, Gabriel Tadeo Vazquez Ballesteros 
	and Mario Guzman Silverio

	Description: class for representing the Book Scanning Problem and storing the
	information of an instance.
********************************************************************************/


#ifndef __PROBLEM_H__
#define __PROBLEM_H__

#include <bits/stdc++.h>
using namespace std;


struct Library{
	//int N;
	int T;
	int M;
	vector<int> IDs;
};

class Problem {
	public:
		Problem(const string &fileName);
		~Problem(){ }
		int B; //Number of books
		int L; //Number of Libraries 
		int D; //Period of days to scan books
		int maxBookValue; //Value of the most valuable book
		vector<int> S; //Scores of each book
		vector<Library> libraries; //Libraries
		vector< vector<int> > book2library; //List of libraries where each book is present
		vector< vector < int > > librariesToBook; //List of books at each library
};


#endif
