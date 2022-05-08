#include <bits/stdc++.h>
using namespace std;
int N, M, cont;
vector<bool> marked;
vector<vector<int> > adj;
void Components(int node)
{
   cont++;
   marked[node]=1;
   for(auto e:adj[node])
      if(!marked[e])
      Components(e); 
}
int main()
{
  int t;
  cin >>t;
  while(t--)
  {
    cin >> N >> M;
    adj.assign(N, vector<int>()); 
    marked.assign(N, false);
    for(int i = 0; i < M; i++)
    {
      int a,b;
      cin >>a >>b;
      a--, b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int maxs=-1;
    for(int i = 0; i < N; i++)
    {
	if(marked[i])continue;
	cont=0;
	Components(i);
	maxs=max(maxs, cont);
    }  
    cout << maxs<<endl;
  }
  return 0;
}
