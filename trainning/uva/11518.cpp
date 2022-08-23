#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
int visited[MAX_N], cont;
vector<vector<int>>adj;
void dfs(int node)
{
  if(visited[node]) return;
  visited[node]=1;
  cont++;
  for(auto idx:adj[node])
    dfs(idx);
}
int main()
{
  int ite, n, m , l;
  cin>>ite;
  while(ite--)
  {
     cin>>n>>m>>l;
     adj.assign(n, vector<int>());
     cont = 0;
     memset(visited, 0, sizeof visited);
     int x, y;
     for(int i = 0; i < m; i++){
	     cin>>x>>y; 
	     adj[x-1].push_back(y-1);
//	     adj[y-1].push_back(x-1);
     }
     int d;     
     for(int i = 0; i < l; i++)
     {
	     cin>>d;
	     dfs(d-1);
     }
     cout << cont<<endl;
  }
  return 0;
}
