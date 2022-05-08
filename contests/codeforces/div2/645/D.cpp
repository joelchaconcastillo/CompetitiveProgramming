#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
  long long n, x;
  cin>>n>>x;
  vector<int> d(2*n), ac(2*n+1,0), score(2*n+1, 0);
  for(int i = 0; i < 2*n; i++)
  {
     if(i<n)
      cin >>d[i], d[n+i]=d[i];

     ac[i+1]=d[i];
     score[i+1] = (d[i]*(d[i]+1))/2;
     ac[i+1] +=ac[i], score[i+1] += score[i];
  }
  int maxv = 0;
  for(int j=0; j<=2*n; j++)
  {
    if(ac[j]<x)continue;
    int i = upper_bound(ac.begin(), ac.end(), ac[j]-x)-ac.begin();
    int sc = score[j]-score[i];
    int nd = ac[j]-ac[i];
    if( i> 0 && nd < x)
    {
	int over = nd+d[i-1]-x;
	sc += (d[i-1]*(d[i-1]+1))/2;
	sc -= over*(over+1)/2;
    }
    maxv = max(maxv, sc);
  } 
  cout << maxv<<endl;
  return 0;
}
