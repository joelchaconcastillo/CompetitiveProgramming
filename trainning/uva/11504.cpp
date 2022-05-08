#include <bits/stdc++.h>
#define MAX_N 1e6
using namespace std;
int t, n, m, pathcounter, SSCC;
vector<vector<int> > adj;
vector<int> dfs_low, dfs_num, S, visited, IdSCC;
void dfs(int node)
{
   dfs_low[node]=dfs_num[node]=pathcounter++;
    visited[node]=1;
   S.push_back(node);
   for(auto next:adj[node])
   {
      if(dfs_num[next]==MAX_N)
         dfs(next);
      if(visited[next])
      dfs_low[node]=min(dfs_low[next], dfs_low[node]); 
   } 
   if( dfs_low[node]==dfs_num[node])
    {
       while(true)
   	{
	  int current = S.back();
	  S.pop_back();
          visited[current]=0;
          IdSCC[current]=SSCC;
          if(current==node)break;
	}
        SSCC++;
    }
}
int main()
{
  cin >>t;
  while(t--)
  {
    cin >>n>>m;
    adj.assign(n , vector<int> ());
    dfs_low.assign(n, MAX_N);
    dfs_num.assign(n, MAX_N);
    visited.assign(n, 0);
    IdSCC.assign(n, -1);
    pathcounter=SSCC=0;
    for(int i = 0; i < m; i++)
    {
       int a,b;
       cin >>a >>b;
       a--,b--;
       adj[a].push_back(b);
    }
    for(int i = 0 ; i < n; i++)
      if( dfs_num[i]==MAX_N)
	  dfs(i); 
     vector<vector<int> > newadj(SSCC);
     int indegree=0;
     for(int i = 0; i < n ; i++)
     {
        for(auto e:adj[i])
	   if(IdSCC[i]!=IdSCC[e]) 
	     newadj[IdSCC[e]].push_back(IdSCC[i]);
     }
     for(int i = 0; i < SSCC ; i++)
     {
	if(newadj[i].empty())indegree++;
     }
     cout << indegree<<endl;
  }
  return 0;
}
