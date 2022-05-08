#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  while(t--)
 {
     int n;
     cin>>n;
     vector<int> a(n), dp(n);
     for(int i = 0; i < n; i++) cin>>a[i];
     dp[n-1]=a[n-1];
     for(int i = n-2; i>=0; i--)dp[i]=min(a[i], dp[i+1]);
     int maxv = INT_MIN;
     for(int i = 0; i < n-1; i++) maxv=max(maxv, a[i]-dp[i+1]);
     cout << maxv<<endl;
 }
  return 0;
}
