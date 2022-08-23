#include <bits/stdc++.h>
using namespace std;
//vector<vector<int>> adj;
map<int,  map<int, int> > adj;
int main()
{
  int NC, i, j, Ncase=1;
  while( cin >> NC && NC != 0)
  {
     adj.clear();
      while(NC--) //read netwrok connections...
      {
 	cin >> i >> j;
	adj[i][j] = 0;
	adj[j][i] = 0;
      } 

      while(cin >> i >> j && (i > 0 || j>0))
      {
	if( adj.find(i) != adj.end())
	{
	        queue<pair<int, int> > qq;
	        qq.push(make_pair(i,j));
	        unordered_map<int, bool> ckd;
		ckd[i] = true;
		while(!qq.empty()) //bfs...
		{
		  pair<int, int> pp = qq.front();
	          qq.pop();
		  ckd[pp.first]=true;
		  if( pp.second == 0) continue;
		  for(auto nd = adj[pp.first].begin(); nd != adj[pp.first].end(); nd++)
		  {
		      if(ckd[nd->first] ) continue;
		      qq.push(make_pair(nd->first, pp.second-1));
		  } 
		}
	   cout << "Case "<<Ncase++<<": "<<(int) adj.size() - (int) ckd.size() << " nodes not reachable from node "<<i <<" with TTL = " <<j<<"."<<endl;
	}
	else
	cout << "Case "<<Ncase++<<": "<<(int) adj.size() << " nodes not reachable from node "<<i <<" with TTL = " <<j<<"."<<endl;
      }
  }
  return 0;
}
