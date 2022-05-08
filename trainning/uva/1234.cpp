#include <bits/stdc++.h>
#define MAX_NODE 10000
using namespace std;
int c, n, m, totoalsum;
vector<int> p, r;
vector<pair<int, pair<int, int> > > edges;
int find(int node){return (node == p[node])? node:(p[node] = find(p[node]));}
void unionf(int a, int b)
{
   int pa = find(p[a]), pb = find(p[b]);
   if(pa == pb) return;
   if(r[pa] > r[pb]) p[pb] = pa;
   else
   {
      p[pa] = pb;
      if(r[pa] == r[pb]) r[pb]++;
   } 
}
int modified_kruskal()
{
   partial_sort(edges.begin(), edges.begin()+m, edges.end());
   int idx = 0, cont = 2;
   unionf(edges[idx].second.first, edges[idx].second.second);
   totoalsum += edges[idx].first;
   idx++;
   while(idx < m && cont < n)
   {
	if(find(edges[idx].second.first) != find(edges[idx].second.second))
	{
	   unionf(edges[idx].second.first, edges[idx].second.second);
	   totoalsum += edges[idx].first;
	   cont++;
	}
	idx++;
   }
  return totoalsum;
}
int main()
{
  p.assign(MAX_NODE, 0);
  r.assign(MAX_NODE, 0);
  int c;
  cin >> c;
  while(c--)
  {
     totoalsum=0;
     edges.clear();
     cin >> n >>m;
     for(int i = 0; i < n; i++) p[i]=i, r[i]=0; 
     for(int i = 0; i < m; i++)
     { 
	int a, b, w;
	cin >> a >> b >> w;
        totoalsum +=w;
	edges.push_back(make_pair(-w, make_pair(a-1, b-1)));
     }
     cout << modified_kruskal() <<endl;
  }
  return 0;
}
