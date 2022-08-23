#include <bits/stdc++.h>
#define MAX_M 200000
using namespace std;
int main()
{
   int n, m;
   bool taken[MAX_M];
   vector<vector<pair<int, int> > > adj;
   while(cin >> n >> m) 
   {
      if(n == 0 && m == 0) break;
      adj.assign(n, vector<pair<int, int>> ());
      memset(taken, false, sizeof taken);
      int x,y,z, totalcost =0;
      for(int i = 0; i < m; i++)
      {
	cin >> x >> y >> z;
	totalcost += z;
	adj[x].push_back(make_pair(y, z));
	adj[y].push_back(make_pair(x, z));
      }
      priority_queue<pair<int, int> > pq;
      int cost = totalcost;
      taken[0] = 1;
      for(auto idx:adj[0])  pq.push(make_pair(-idx.second, -idx.first));

      while(!pq.empty())
      {
	pair<int, int> ii = pq.top();pq.pop();
	if(taken[-ii.second]) continue;
	cost += ii.first;
	taken[-ii.second] =1;
	for(auto idx:adj[-ii.second])
	{
	  if(!taken[idx.first]) 
	      pq.push(make_pair(-idx.second, -idx.first));
	}
      }
	cout << cost <<endl;
   }
   return 0;
}
