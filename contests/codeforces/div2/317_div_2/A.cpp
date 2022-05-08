#include <bits/stdc++.h>
using namespace std;
int main()
{
  long int na, nb, k, m, boundk, boundm;
  cin >> na >> nb;
  cin >> k >>m;
  for(int i = 1; i <= na ; i++)
  {
	long tmp;
	cin >>tmp;
     if( i == k ) boundk=tmp;
  }
  for(int i = 1; i <= nb ; i++)
  {
	long tmp;
	cin >>tmp;
	if( i == nb-m+1) boundm = tmp ;
  }
  if(boundk < boundm ) cout << "YES"<<endl;
  else cout << "NO"<<endl;
  return 0;
}
