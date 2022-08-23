#include <bits/stdc++.h>
#define MAX_N 2000
using namespace std;
int p[MAX_N], r[MAX_N];
int finds(int i){return  (i == p[i])?i:(p[i] = finds(p[i]));}
void unions(int i, int j)
{
  i = finds(i), j = finds(j);
  if(i==j) return;
  if(r[i] <  r[j]) p[i] = j;
  else
  {
    p[j] = i;
    if(r[i] == r[j]) r[i]++;
  }
}
int main()
{
  int n, m;
  while(cin >> n >> m)
  {
     if(n==0 && m==0) break;
     set<int> W;
     memset(r, 0, sizeof r);
     vector<pair<int, pair<int, int> > > Edges(m);
     int u, v, w;
     for(int i = 0; i < n; i++) p[i]=i;
     for(int i = 0; i < m; i++)
     { 
        cin >> u >> v >> w;
        Edges[i] = (make_pair(w, make_pair(u, v))); 
        W.insert(w);
     }
     sort(Edges.begin(), Edges.end());
     int idx = 0;
     while(idx < m)
     {
	pair<int, int> &e = Edges[idx].second;
	if( finds(e.first) != finds(e.second))
	{
	   W.erase(W.find(Edges[idx].first));
	   unions(e.first, e.second);
	}
	idx++;
     }
     if(W.empty()) cout << "forest";
     else
     {
	int idx = 0;
        for(auto i:W){cout << i; if(idx < W.size()-1) cout << " "; idx++;}

     }
	cout << endl;
  }
  return 0;
}
