#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  for(int i = 0; i < t; i++)
  {
     long long n;
     cin >>n;
     n = n/2 + n%2  -1;
	cout << n <<endl;
  }
  return 0;
}
