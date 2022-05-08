#include <bits/stdc++.h>
#define MAX_N 200001
using namespace std;
int main()
{
  int t;
  int sum[MAX_N], dp[MAX_N];
  cin>>t;
  while(t--)
  {
     int n;
     cin>>n;
     memset(sum, 0, sizeof sum);
     memset(dp, 0, sizeof dp);
     int d;
     for(int i = 0; i < n ; i++) cin>> d, sum[d]++;
     for(int i = 1; i < MAX_N; i++)
     {
        dp[i] += sum[i];
	for(int j = 2*i; j < MAX_N; j +=i)
	   dp[j] = max(dp[j], dp[i]);
     }
     cout << n-*max_element(dp, dp+MAX_N)<<endl;
  }
  return 0;
}
