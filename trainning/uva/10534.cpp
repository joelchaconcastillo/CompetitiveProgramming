#include <bits/stdc++.h>
#define MAX_N 10001
using namespace std;
int n;
void lis(int d[MAX_N], int dp[MAX_N])
{
     for(int i = 0; i<n; i++)
     {
        for(int j = 0; j < i; j++) if(d[j] < d[i]) dp[i] = max(dp[i], dp[j]+1);
     }
}
void lis2(int d[MAX_N], int dp[MAX_N])
{
     vector<int> q;
     for(int i = 0; i<n; i++)
     {
          int a = lower_bound(q.begin(), q.end(), d[i]) - q.begin();
          if(a>=q.size()) q.push_back(d[i]); 
	  else if(d[i]<q[a])q[a] = d[i];
	   dp[i] = a+1;
     }
}
int main()
{
  int d[MAX_N], dp[MAX_N], dm[MAX_N];
  while(cin>>n)
  {
     fill_n(dp, n, 1);
     fill_n(dm, n, 1);
     for(int i = 0; i < n; i++)
       cin>>d[i];
     int maxc = 0;
     lis2(d, dp);
     reverse(d, d+n);
     lis2(d, dm);
     reverse(dm, dm+n);
     for(int i = 0; i < n; i++) maxc=max(maxc, min(dp[i], dm[i]));
     cout << (maxc-1)*2+1<<endl;
  }
  return 0;
}
