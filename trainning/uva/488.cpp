#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T, F, A;
  cin >> T;
  while(T--)
  {
     cin >> A >> F;
     int nr = A*2-1;
     while(F--)
     {
     for(int i =  0, j = nr-1; i < nr; i++,j--)
     {
 	int v = min(i,j);	
	for(int k = 0; k <= v; k++)
	cout << v+1;
	cout << endl;
     } 
	if(F)
	cout <<endl;
     }
     if(T)
     cout <<endl;
  }
  return 0;
}
