#include<bits/stdc++.h>
#define MAX_N 10000
using namespace std;
int main()
{
  int t, nc, tp;
  cin >> t;
  int dp[2*MAX_N];
  while(t--)
  {
    cin >> tp>>nc;
    fill_n(dp, 2*MAX_N, MAX_N);
    int d;
    cin >> d;
    dp[0] = 0;
    dp[d] = 1;
     for(int i = 1; i < nc; i++)
     {
        cin >> d;
        for(int j = 2*MAX_N-d-1; j >=0; j--)
	{
	   if(dp[j] != MAX_N)
	   dp[j+d] = min( dp[j]+1, dp[j+d]);
	}
     }
    for(int i = tp; i <=2*MAX_N; i++) 
	{
	   if(dp[i] != MAX_N)
	   {
	    cout << i<<" "<<dp[i]<<endl;
	    break;
	   }
	}
  }
  return 0;
}
