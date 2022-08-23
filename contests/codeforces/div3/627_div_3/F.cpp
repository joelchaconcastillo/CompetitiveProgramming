/*
  version studied from codeforces..
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > edges;
vector<int> dp, color, v;
int n;
void dfs(int c, int p=-1)
{
   dp[c] = color[c];
   for(auto &to: edges[c])
   {
      if( to == p) continue;
      dfs(to, c);
      dp[c] += max(0, dp[to]);
   }
}
void dfs2(int c, int p=-1)
{
   v[c] = dp[c];
   for(auto &to: edges[c])
   {
      if( to == p) continue;
      dp[c] -= max(0, dp[to]);
      dp[to] +=  max(0, dp[c]);
      dfs2(to, c);
      dp[to] -= max(0, dp[c]);
      dp[c] += max(0, dp[to]);
   }
}
int main()
{
  cin >>n; 
  color.assign(n,0);
  v.assign(n,0);
  edges.assign(n, vector<int>());
  dp.assign(n, 0);
  for(int i = 0; i < n; i++)
  {
	 cin >> color[i];
     if(color[i] == 0)color[i]=-1;
  }
  for(int i = 0; i < n-1; i++)
  {
     int a,b;
     cin >> a >> b;
     edges[--a].push_back(--b);
     edges[b].push_back(a);
  }
  dfs(0);//filling the initial dp
  dfs2(0); //sort-of incremental update
  for(int i = 0; i < n; i++) cout << v[i]<< " ";
  return 0;
}
