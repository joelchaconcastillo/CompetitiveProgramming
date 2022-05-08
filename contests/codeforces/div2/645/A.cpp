#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  while(t--)
  {
	long int n,m;
	cin >>n >>m;
	cout<<fixed << (long int)ceil( (n*m)/2.0)<<endl;
  }
  return 0;
}
