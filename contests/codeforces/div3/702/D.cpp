#include <bits/stdc++.h>
using namespace std;
int n, d[101], a[101];
void dfs(int l, int r, int depth)
{
   if( l == r) return;
   pair<int, int> maxi (-1, -1);
   for(int i = l; i < r; i++)
	   if( maxi.first < a[i])maxi = make_pair(a[i], i);
   d[maxi.second] = depth;
   dfs(l, maxi.second, depth+1);
   dfs(maxi.second+1, r, depth+1);
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     cin >> n;
     for(int i = 0; i < n; i++) cin>>a[i];
     dfs(0, n, 0);
     for(int i = 0; i < n; i++) cout << d[i]<<" ";
     cout <<endl;
  }
  return 0;
}
