#include <bits/stdc++.h>
#define MAX_V 1e6
using namespace std;
vector<vector<int> > adj;
vector<int> fv, path, is, component;
vector<bool> assigned;
int limit;
void dfs(int node, int t)
{
   path.push_back(node);
   fv[node]=t;
   for(auto i:adj[node])
   {
	if(fv[i]==MAX_V)
	   dfs(i, t+1);
	else //back edge
	{
	  if( t-fv[i]+1 >= limit && component.empty())
	  {
	     int idx = path.size()-1;
	     component.push_back(i);
	     while(idx>=0 && path[idx]!=i) component.push_back(path[idx--]);
	  }
	}
   }
   if(!assigned[node])
      for(auto i:adj[node]) assigned[i]=1;
   path.pop_back();
}
int main()
{
  int n, m;
  cin >>n>>m;
  limit = ceil(sqrt((double)n));
  adj.assign(n, vector<int>());
  fv.assign(n, MAX_V);
  assigned.assign(n, 0);
  for(int i = 0; i < m; i++)
  {
	int a,b;
	cin >>a>>b;
	a--,b--;
	adj[a].push_back(b);
	adj[b].push_back(a);
  }
  dfs(0, 0);
  if(component.size()>=limit){
     cout << 2 <<endl;
     cout << component.size()<<endl;
     for(int i = 0; i < component.size(); i++)cout << component[i]+1<<" ";
     cout <<endl;
  }
  else
  {
     cout <<1<<endl;
     for(int i = 0, j=0; i < n && j < limit; i++) if(!assigned[i])cout<< i+1<<" ", j++;
  cout<<endl;   
  }
  return 0;
}
