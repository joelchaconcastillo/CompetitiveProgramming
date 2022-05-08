#include <bits/stdc++.h>
#define MAXL 1000
using namespace std;
int L;
int points[52];
int memo[MAXL*MAXL];
int cut(int l, int r)
{
  if(l+1==r) return 0;
  if(memo[l*MAXL+r] != -1) return memo[l*MAXL+r];
  int mincost = 10000000;
  for(int i = l+1; i < r; i++)
     mincost = min(mincost, cut(l, i) + cut(i, r) + points[r] - points[l]); 
  return memo[l*MAXL+r]=mincost;
}
int main()
{
  while(cin >> L)
  {
     if(L==0) break;
     memset(memo, -1, sizeof memo);
     int n;
     cin >> n;
     points[0]=0;
     points[n+1]=L;
     for(int i = 1; i <= n; i++)cin >> points[i];
     cout << "The minimum cutting is " << cut(0, n+1)<<"."<<endl;
  }
  return 0;
}
