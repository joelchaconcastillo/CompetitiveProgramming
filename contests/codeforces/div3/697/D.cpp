#include <bits/stdc++.h>
#define MAX_N 200000
#define INF 1e9
using namespace std;
int main()
{
  int t;
  long long n,m, a[MAX_N], b[MAX_N];
//  long long dp[2*MAX_N];
  cin>>t;
  while(t--)
  {
    vector<int> one, two;
    long long acum_one=0, acum_two=0;
    cin >> n>>m;
    for(int i = 0; i <n; i++)
	cin >>a[i];
    for(int i = 0; i <n; i++)
    {
	cin >>b[i];
	if(b[i]==1)
	   one.push_back(a[i]);
	else two.push_back(a[i]), acum_two +=a[i];
    }
    sort(one.rbegin(), one.rend());
    sort(two.rbegin(), two.rend());
   int j = two.size();
   int minv=INT_MAX;
   for(int i = 0; i <= one.size(); i++)
   {
      while(j>0 && acum_one+acum_two-two[j-1] >=m) j--,acum_two -=two[j];
      if( acum_one + acum_two >=m) minv = min(minv, 2*j+i);
      if(i!=one.size())acum_one +=one[i];
   }
   minv = (minv == INT_MAX)? -1: minv;
   cout << minv<<endl;
//    int maxcost = 2*n+10;
//    fill_n(dp, maxcost,INF);
//    dp[0] = m;
//   for(int i = 0; i <n; i++)
//   {
//      for(int j = maxcost-1; j>=0;j--)
//	if( dp[j]!=INF )//&& dp[j]-a[i] >=0)
//		dp[j+b[i]] = min(dp[j+b[i]], dp[j]-a[i]);
//   } 
//   for(int i = 0; i < maxcost; i++)cout << dp[i]<< " ";
//   cout <<endl;
//   int i = 0;
//   for(; i < maxcost; i++) if(dp[i] <= 0) break;
//   if(i==maxcost) cout << "-1\n";
//   else cout <<i<<endl;
  }
  return 0;
}
