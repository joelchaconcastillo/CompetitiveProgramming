#include<bits/stdc++.h>
using namespace std;
int main()
{
   int T;
   cin >> T;
   for(int i = 0; i < T; i++)
   {
	  int N;
	  cin >>N;
	  int prev ;
	  cin >>prev;
	  int h=0,l=0;
	  for(int j = 0; j < N-1; j++)
	  {
		  int current;
		  cin >> current;
		  int diff = current - prev ;
		  if(diff> 0)
			  h++;
		  else if(diff  < 0)  l++;

	      prev = current;
	  }
	  cout << "Case "<<i+1<<": "<< h << " "<<l <<endl;
   }
}
