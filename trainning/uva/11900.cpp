#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  for(int c= 1; c <=t; c++)
  {
    int n,P,Q;
    cin >>n >>P>>Q;
    int maxeggs=0, sumgm=0;
    for(int i = 0; i < n ; i++)
    {
	int gm;
	cin >>gm;
	if(gm+sumgm <= Q) sumgm +=gm, maxeggs++;
    } 
    cout<<"Case "<<c<<": " << min(maxeggs, P)<<endl;
  }
  return 0;
}
