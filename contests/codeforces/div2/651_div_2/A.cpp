#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  for(int i = 0; i < t; i++)
  {
	int n,o;
	cin>>n;
	o = (n==1)?1:(n/2);
	cout <<o <<endl;
  }
  return 0;
}
