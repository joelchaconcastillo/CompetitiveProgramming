#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > edges;
vector<bool> marked;
int ncomponents;
void dfs(int node)
{
  marked[node]=true; 
  ncomponents++;
  for(auto ed:edges[node])
     if(!marked[ed]) dfs(ed);
}
int main()
{
   int t; 
   cin >> t;
   cin.ignore();
   while(t--)
   {
      edges.assign(30, vector<int>());
      marked.assign(30, false);
      vector<bool> exist(30, false);
      string st=" ";
      while(  getline(cin, st) && st[0]!='*')
      {
           int a = st[1]-'A', b = st[3]-'A';
           edges[a].push_back(b);
           edges[b].push_back(a);
      }
      getline(cin, st);
      int ntree = 0, nacorn=0;
      for(auto i:st)
      {
	if(i==',')continue;
	if(marked[i-'A'])continue;
        ncomponents=0;
        dfs(i-'A');
	if(ncomponents>1)ntree++;
	else nacorn++;
      }
	cout << "There are "<<ntree<<" tree(s) and "<<nacorn<<" acorn(s)."<<endl;
   }
   return 0;
}
