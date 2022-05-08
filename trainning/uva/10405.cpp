#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
int dp[MAX_N*MAX_N];
int main()
{
  string s1,s2;
  while(getline(cin ,s1) && getline(cin, s2))
  {
     int l1 = s1.size(), l2 = s2.size();
     memset(dp, 0, sizeof dp);
     for(int i = 1; i <= l1; i++)
     {
        for(int j = 1; j <= l2; j++)
	{
	   dp[i*MAX_N + j] = dp[(i-1)*MAX_N + j-1];
	   if( s1[i-1] == s2[j-1])dp[i*MAX_N + j] +=1;
	   else dp[i*MAX_N + j]=-1000000;
           dp[i*MAX_N+j] = max(dp[i*MAX_N+j], dp[(i-1)*MAX_N+j]);
           dp[i*MAX_N+j] = max(dp[i*MAX_N+j], dp[i*MAX_N+j-1]);
	}
     }
     cout << dp[ l1*MAX_N + l2]<<endl;
  }
  return 0;
}
