#include <bits/stdc++.h>
using namespace std;
int main()
{
   int T;
   cin >>T;
   for(int i = 1; i<=T; i++)
   {
	int N, TotalCostMile=0, TotalCostJuice=0;

	cin >>N;
        for(int j = 0; j < N; j++)
	{
	  int seconds;
	  cin >> seconds;
	  
	  TotalCostMile +=  (int)( ceil((seconds+1)/30.0))*10;
	  TotalCostJuice +=  (int)( ceil((seconds+1)/60.0))*15;
	}
	cout << "Case " << i <<": ";
	if( TotalCostMile < TotalCostJuice) cout << "Mile "<<TotalCostMile<<endl;
	else if( TotalCostMile > TotalCostJuice) cout << "Juice "<<TotalCostJuice<<endl;
	else cout << "Mile Juice "<< TotalCostMile<<endl;
   }
}
