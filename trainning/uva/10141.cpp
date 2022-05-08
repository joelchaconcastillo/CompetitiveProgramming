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
   int n, p, contrfp=0;
   while(scanf("%d %d\n", &n, &p) != 0 && (n && p))
   {		
	if(contrfp>0) cout << endl;
     contrfp++;
     int maxcompliance = -1;
     double lowestprice = 10000000;
     string bycompliance, byprice;
     priority_queue< pair<int, pair< double, int> > > pq;
     int cont = 0;
      vector<string> table_proposal(p);
     for(int ni = 0; ni < n; ni++)
     {
	string trash;
	getline(cin, trash);
     }
     for(int pi = 0; pi < p; pi++)
     {
        string proposalmet;
	getline(cin, proposalmet);
	double price;
        int rmet;
	scanf("%lf %d\n", &price, &rmet);
	table_proposal[pi] = proposalmet;
	pq.push( make_pair( rmet, make_pair( -price, -pi) ) );
        for(int rm = 0; rm < rmet; rm++)
	{
	  string trash;
	  getline(cin, trash);
	}
     }
	cout << "RFP #"<<contrfp << "\n"<< table_proposal[-1*pq.top().second.second] <<endl;
//         cout << "RFP #" << contrfp << "\n"<< byprice<<endl;
   } 
   return 0;
}
