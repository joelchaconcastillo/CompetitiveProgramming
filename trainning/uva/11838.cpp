#include <bits/stdc++.h>
#define MAX_N 1e4
using namespace std;
int ncomp, pathcont;
vector<vector<int> > adj;
vector<bool>visited;
vector<int> dfs_low, dfs_num, S;
void dfs(int node)
{
   dfs_low[node] = dfs_num[node]=pathcont++;
   visited[node]=1;
   S.push_back(node);
   for(auto next:adj[node])
   {
     if(dfs_low[next] == MAX_N)
         dfs(next);
     if(visited[next])
       dfs_low[node]=min(dfs_low[node], dfs_low[next]);
   }
   if( dfs_low[node]==dfs_num[node])
   {
      ncomp++;
      while(true)
      {
         int c = S.back();
         visited[c]=0;
	 S.pop_back();
         if(c==node)break;
      }
   }
}
int main()
{
  int N, M;
  while(true)
  {
     cin >>N>>M;
     if(N==0 && M==0) break;
     ncomp=pathcont=0;
     adj.assign(N, vector<int>());
     visited.assign(N, false);
     dfs_low.assign(N, MAX_N);
     dfs_num.assign(N, MAX_N);
     S.clear();     
     for(int i = 0; i < M; i++)
     {
       int a,b,p;
       cin >>a >>b>>p;
       a--, b--;
       adj[a].push_back(b);
       if(p==2)adj[b].push_back(a);
     }
     for(int i = 0; i < N; i++)
     {
        if(dfs_low[i]==MAX_N)dfs(i);
        if(ncomp>1)break;
     }
     if(ncomp>1)cout << 0<<endl;
     else cout << 1<<endl;
  }
  return 0;
}
