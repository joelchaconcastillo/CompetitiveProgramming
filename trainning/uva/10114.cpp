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
  int monthsloan, ndepreciationrecords;
  double downpayment, amountloan;
  double records[101];
  
  while(true)
  {
     //scanf("%d %lf %lf %d", &monthsloan, &downpayment, &amountloan, &ndepreciationrecords);
     cin >>monthsloan>> downpayment>> amountloan >>ndepreciationrecords;
     if( monthsloan < 0) break;
     int m; 
     double dp;   
     for(int i = 0; i < ndepreciationrecords; i++)
	{

//	  scanf("%d %lf", &m, &dp);
	  cin >> m >> dp;
	  for(int j = m; j < 101; j++) records[j] = dp;
	}
  
     double owns = amountloan;
     double worths = (amountloan+downpayment)*( 1 - records[0]) ;
     double monthpay = amountloan/monthsloan;   
     int cont = 0;
      while (worths< owns) {
			cont++;
			owns -= monthpay;
			worths= worths* (1 -records[cont]);
		}   
	//cout << cont << " month";
	//if( cont != 1) cout << "s";
	//cout <<endl;
      printf("%d %s\n", cont, (cont!=1)?"months":"month" );
 //    scanf("%d %lf %lf %d", &monthsloan, &downpayment, &amountloan, &ndepreciationrecords);
  }
   return 0;
}
