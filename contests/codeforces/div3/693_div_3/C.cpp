#include <bits/stdc++.h>
#define M 300001
using namespace std;
int main()
{
  int t, n;
  int d[M], memo[M];
  cin >> t;
  while(t--)
  {
    cin >>n ;
    for(int i = 0; i < n; i++) cin >>d[i];
    int maxs = 0;
    for(int i = n-1; i >=0; i--)
    { 
      memo[i] = d[i];
      if( i+d[i] < n) memo[i] += memo[i+d[i]];
      maxs  = max(maxs, memo[i]);
    }
    cout << maxs<<endl;
  }
  return 0;
}
