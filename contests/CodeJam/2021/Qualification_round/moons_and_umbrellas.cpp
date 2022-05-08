#include <bits/stdc++.h>
#define MAX_S 1001
using namespace std;

int X, Y; 
int cost(int i, int j)
{
   if( i == 0 && j==1)return X;
   if( i == 1 && j==0) return Y;
   return 0;
}
int main()
{
  int T, n;
  int dp[2*MAX_S];
  cin >>T;
  for(int ite = 1; ite <=T; ite++)
  {
    string st;
    cin >>X >> Y>>st;
    n=st.size();
    for(int i = 0; i < n; i++) if(st[i]=='C')st[i]='0';else if(st[i]=='J')st[i]='1';
    fill_n(dp, MAX_S*2, 1e8);
    dp[0]=dp[1]=0; 
    for(int i =1; i < n; i++)
    {
      int col_prev = st[i-1]-'0', col = st[i]-'0';
      if(st[i-1] != '?')
      {
	 if(st[i] != '?')
	 {
	   dp[2*i + col] = dp[2*(i-1)+col_prev]+cost(col_prev, col);
	   dp[2*i + 1-col] =1e8;
	 }
	else if(st[i] == '?')
	{
	   dp[2*i] = dp[2*(i-1) + col_prev] + cost(col_prev, 0);
	   dp[2*i+1] = dp[2*(i-1) + col_prev] + cost(col_prev, 1);
	}
      }
      else if(st[i-1]=='?')
      {
        if(st[i]=='?')
	{
          dp[2*i] = min(dp[2*(i-1)]+cost(0,0), dp[2*(i-1)+1]+cost(1,0));
          dp[2*i+1] = min(dp[2*(i-1)]+cost(0,1), dp[2*(i-1)+1]+cost(1,1));
	}
	else if(st[i]!='?')
	{
	   dp[2*i + col] = min(dp[2*(i-1)]+cost(0,col), dp[2*(i-1)+1]+cost(1,col));
	   dp[2*i + 1-col] = 1e8;
	}
      }
    }
    cout <<"Case #"<<ite<<": ";
    if(st[n-1]!='?') cout << dp[2*(n-1)+st[n-1]-'0']<<endl;
    else cout << min(dp[2*(n-1)],dp[2*(n-1)+1])<<endl;
//    exit(0);

  }
  return 0;
}
