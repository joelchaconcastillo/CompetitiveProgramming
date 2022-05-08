#include <bits/stdc++.h>
#define MAX_N 1e6
using namespace std;
int N, cpath, idroot, croot;
vector<vector<int> > adj;
vector<int> dfs_low, dfs_num, parent, criticalpoints;
void dfs(int node)
{
   dfs_low[node]=dfs_num[node]=cpath++;
   for(auto next:adj[node])
   {
     if(dfs_num[next]==MAX_N) //Explore edges..
     {
      if(idroot==node)croot++;
      parent[next]=node;
      dfs(next);
     if( dfs_low[next] >= dfs_num[node]) criticalpoints[node]=1;
      dfs_low[node] = min(dfs_low[node], dfs_low[next]);
     }
     else if(parent[next]!= node) //backedges.. be carefull with parent edges
     {
        dfs_low[node] = min(dfs_low[node], dfs_num[next]);
     }
   }
}
int main()
{
  while(cin >>N)
  {
     if(N==0)break;
     adj.assign(N, vector<int>());
     dfs_low.assign(N, MAX_N);
     dfs_num.assign(N, MAX_N);
     criticalpoints.assign(N, false);
     parent.assign(N, -1);
     cpath=0;
     string line;
     cin.ignore();
     while(getline(cin, line) && line[0]!='0')
     {
        istringstream iss(line);
        int a, b;
        iss>>a;
        while(iss>>b)adj[a-1].push_back(b-1), adj[b-1].push_back(a-1);
     }
     idroot=croot=0;
     for(int i = 0; i < N; i++)
     {
        if(dfs_num[i]==MAX_N)
        {
          idroot=croot=0;
          dfs(i);
          criticalpoints[idroot] = (croot>1);
        }
     }
     int nc=0;
     for(auto i:criticalpoints) nc +=i;
     cout << nc<<endl;
  } 
  return 0;
}
