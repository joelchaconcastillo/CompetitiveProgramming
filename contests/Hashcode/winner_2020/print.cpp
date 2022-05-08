#include "Individual.h"

void Individual::print(const string &fileName) {
/*
    vector < int > librariesToPrint;
    vector < vector< int > > booksPerLibrary((problem->L), vector<int>());

    int lenPer = (int)(permutationLib).size();
    slotsPerLib.assign(lenPer, 0);
    int Dleft = (problem->D);
    for(int i = 0; i < lenPer; i++) {
        if( (problem->libraries)[ permutationLib[i] ].T <= Dleft ) {
            librariesToPrint.push_back( permutationLib[i] );
            Dleft -= (problem->libraries)[ permutationLib[i] ].T;
        }
    }

    for(int i = 0; i < (problem->B); i++) if(book2lib_assign[i] != -1) booksPerLibrary[ book2lib_assign[i] ].push_back(i);

*/

    ofstream ofs(fileName, ifstream::out);
		/*
		int numberLib = 0;
		for(int i = 0; i < (int)librariesToPrint.size(); i++){
			if( booksPerLibrary[ librariesToPrint[i]].size() != 0){
				numberLib++;
			}
		}
    ofs << numberLib << "\n";
    for(int i = 0; i < (int)librariesToPrint.size(); i++)
    {
        int len = booksPerLibrary[ librariesToPrint[i] ].size();

				if (len){
        	ofs << librariesToPrint[i] <<  " " <<  len << "\n";
      	  for(int j = 0; j < len; j++){
       	     ofs << booksPerLibrary[ librariesToPrint[i] ] [j] << " ";
       	 }ofs << "\n";
				}
    }*/
		ofs << cost << "\n";

    ofs.close();

}
