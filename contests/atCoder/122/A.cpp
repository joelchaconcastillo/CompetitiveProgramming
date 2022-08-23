#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N, s1, s2;
  long long s=0;
  cin >>N;
  s1=0, s2=N-2;
  long long k1 = 0, k2=1,t;

  for(int i = 0; i < N-1; i++) t=k1+k2, k1=k2, k2=t;
	 cout << k2<<endl; 
  for(int i = 0; i < N; i++)
  {
	int d;
	cin >> d;
	if( i > 0 )
	{
	   int k = max(s1, s2);
	   s1++, s2--;
   s += (k2*d)-(k*d);
}
	else  s+=N*d;
  }
  cout << s <<endl;
  return 0;
}
