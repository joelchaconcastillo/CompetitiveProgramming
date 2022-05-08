#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     int n;
     pair<int, int>minv(-1, 10000), maxv(-1,-10000);
     cin>>n;
     for(int i = 0; i < n; i++)
     {
	 int d;
	 cin>>d;
	 if( d < minv.second) minv = make_pair(i, d);
	 if( d > maxv.second) maxv = make_pair(i, d);
     }
     int l=0,r=n-1, t = 0;
     if( minv.first < maxv.first) l=minv.first, r=maxv.first;
     else l=maxv.first, r=minv.first;
     t = l+1+n-r;
     t = min(t, l+1 + (r-l));
     t = min(t, n-r+(r-l));
     cout << t<<endl;

  }
}
