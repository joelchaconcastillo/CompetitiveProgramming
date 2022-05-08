#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long N, Q;
  cin >>N >> Q;
  vector<long long> d(N), dp(N);
  for(int i = 0; i < N; i++)cin>>d[i], dp[i] = d[i]-i-1;
  for(int i = 0;i < Q; i++)
  {
	long long k;
	cin >> k;
	if(dp[N-1]<k)
	{
	   cout <<d[N-1]+ k - dp[N-1] <<endl;
	   continue;
	}
	long long l=0, r=N-1;
	while(l<r)
	{
	    long long m = (l+r)/2;
	    if( dp[m] < k ) l=m+1;
	    else r=m;
	}
	cout << d[l]-1-dp[l]+k <<endl;
  }
  return 0;
}
