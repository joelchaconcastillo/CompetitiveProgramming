#include <bits/stdc++.h>
using namespace std;
int main()
{
  int ab[2], cd[2];
  cin >>ab[0]>>ab[1]>>cd[0]>>cd[1];
  int maxv=-10000;
  for(int i = 0; i <2; i++)
	  for(int j  = 0; j <2;j++)
		  maxv= max(ab[i]-cd[j], maxv);
  cout <<maxv<<endl;
  return 0;
}
