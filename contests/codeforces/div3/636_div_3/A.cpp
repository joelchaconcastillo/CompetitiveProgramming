#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  for(int i = 0; i < t; i++)
  {
     long long n;
     cin >> n;
     long long x_check;
     for(int k = 2; ;k++)
     {
	x_check = -n/(1-pow(2, k));
	if( x_check*(  -(1-pow(2, k))) == n) 
	break;
     }
	cout << x_check<<endl;
  }
  return 0;
}
