#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >>n;
  long long N = (n+1)/2;
  vector<int> d(N);
  long long x;
  for(int i = 0; i < N; i++)cin>> d[i];
  cin >>x; 
  vector<long long > m(N+1, 0);
  long long prefixsum= 0;  
  for(int i = 1; i <= N; i++)
  {
     prefixsum += x - d[i-1];
     m[i] = min(m[i-1], prefixsum);
  }
  long long totalsum = 0;
  for(int i = 0; i < N; i++) totalsum +=d[i];
  for(int k = N; k <= n; k++)
  {
    if( totalsum + m[n-k] > 0){cout << k<<endl; return 0;}
    totalsum +=x;
  }
  cout << -1<<endl;
  return 0;
}
