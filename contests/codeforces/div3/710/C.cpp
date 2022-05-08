#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
       string A, B;
       cin>> A >> B;
       int maxc=0;
       for(int i = 0; i < A.size(); i++)
       {
	   for(int j = 0; j <  B.size(); j++)
	   {
	      int k = 0;
	      while( j+k < B.size() && i+k<A.size() && A[i+k] == B[j+k])k++;
	      maxc=max(maxc, k);
	   }
       }
       cout << A.size() + B.size() - 2*maxc<<endl;
  }
  return 0;
}
