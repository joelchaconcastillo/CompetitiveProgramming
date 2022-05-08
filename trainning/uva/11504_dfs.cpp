#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >adj;
vector<bool> marked;
stack<int> S;
void dfs1(int node)
{
  marked[node]=true; 
  for(auto idx:adj[node])
	if(!marked[idx]) dfs1(idx);
  S.push(node);
}
void dfs2(int node)
{
    marked[node]=true;
    for(auto idx:adj[node])
	if(!marked[idx]) dfs2(idx);
}
int main()
{
   int t, n, m;
   cin >>t ;
   while(t--)
   {
      cin >> n >> m;
      int a, b;
      adj.assign(n, vector<int>());
      marked.assign(n, false);
      for(int i = 0; i < m ; i++)
      {
	cin >>a >>b;
	a--,b--;
       adj[a].push_back(b);
      }
      for(int i = 0; i < n; i++)
      {
         if(!marked[i]) dfs1(i);
      }
      marked.assign(n, false);
      int cont = 0;
      while(!S.empty())
      {
	int current = S.top(); S.pop();
        if(!marked[current]) dfs2(current), cont++;
      }
      cout << cont<<endl;
   }
}
