#include <bits/stdc++.h>
using namespace std;
//Suppress some compilation warning messages (only for VC++ users)
#define _CRT_SECURE_NO_DEPRECATE
//Shortcuts for "common" data types in contests
typedef long long ll; //comments that are mixed in with code
typedef pair<int, int> ii; //are aligned to the right like this
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 //1 billion, safer than 2B for Floyd Warshall's

// Common memset settings
//memset(memo, -1,  sizeof memo); //initialize DP memoization table with -1
//memset(arr, 0, sizeof arr);     // to clear array of integers

//several shorcuts that are frequently used:
// ans = a ? b : c;
// ans +=val
// index = (index+1) %n;
// index = (index + n - 1) % n;
// int ans = (int) ((double)d + 0.5); //for rounding to nearest integer
// ans = min(ans, new_computation);  //min/max shortcut // alternative form but not used in this book: ans<?= new_computation
int main()
{
   int L;
   string D, C;
   map< string, map<string, string> > table;
   table["+x"]["+y"] = "+y" ;
   table["+x"]["-y"] = "-y" ;
   table["+x"]["+z"] = "+z" ;
   table["+x"]["-z"] = "-z" ;
   table["-x"]["+y"] = "-y" ;
   table["-x"]["-y"] = "+y" ;
   table["-x"]["+z"] = "-z" ;
   table["-x"]["-z"] = "+z" ;

   table["+y"]["+y"] = "-x" ;
   table["+y"]["-y"] = "+x" ;
   table["+y"]["+z"] = "+y" ;
   table["+y"]["-z"] = "+y" ;
   table["-y"]["+y"] = "+x" ;
   table["-y"]["-y"] = "-x" ;
   table["-y"]["+z"] = "-y" ;
   table["-y"]["-z"] = "-y" ;

   table["+z"]["+y"] = "+z" ;
   table["+z"]["-y"] = "+z" ;
   table["+z"]["+z"] = "-x" ;
   table["+z"]["-z"] = "+x" ;
   table["-z"]["+y"] = "-z" ;
   table["-z"]["-y"] = "-z" ;
   table["-z"]["+z"] = "+x" ;
   table["-z"]["-z"] = "-x" ;
   while( scanf("%d",&L)==1 &&  L)
   {
   C = "+x";
      for(int i = 0; i < L-1; i++)
	{
		cin >> D;
		if( D != "No")
		C = table[C][D];
	}  
	cout << C<<endl;
   }
	
   return 0;
}
