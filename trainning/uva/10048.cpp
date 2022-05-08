#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
int C, S, Q, root;
int p[MAX_N], r[MAX_N];
vector<pair<int, pair<int, int> > > edges;
vector<vector<pair<int, int>>> path;
int find(int i){return (i==p[i])?i:(p[i]=find(p[i]));}
void uniond(int a, int b)
{
  int pa = find(a), pb = find(b);
  if( pa == pb) return;
  if(r[pa] > r[pb]) p[pb] = pa;
  else
  {
     p[pa] = pb;
     if(r[pa]==r[pb])
        r[pb]++;
  }
}
void kruskal()
{
  path.assign(C, vector<pair<int,int>>());
  sort(edges.begin(), edges.end());
  int idx= 0, cont = 2;
  uniond(edges[idx].second.first, edges[idx].second.second);
  path[edges[idx].second.first].push_back(make_pair(edges[idx].second.second, edges[idx].first));
  path[edges[idx].second.second].push_back(make_pair(edges[idx].second.first,  edges[idx].first));
  idx++;
  while(cont <  C && idx < S)
  {
     if(find(edges[idx].second.first) != find(edges[idx].second.second)) 
     {
        uniond(edges[idx].second.first, edges[idx].second.second);
        path[edges[idx].second.first].push_back(make_pair(edges[idx].second.second, edges[idx].first));
        path[edges[idx].second.second].push_back(make_pair(edges[idx].second.first,  edges[idx].first));
	cont++;
     }
    idx++;
  }
}
int augmented(int current, int prev, int end, int current_max)
{
 if(current == end) return current_max;
 int maxv = -1000;
 for(int i = 0; i < path[current].size(); i++)
 {
   if(path[current][i].first != prev) 
   maxv = max(maxv, augmented(path[current][i].first, current,end, max(current_max, path[current][i].second))); 
 }
 return maxv;
}
int query(int a, int b)
{
   return augmented(a, -1, b, -1000);
}
int main()
{
  int t=1;
  while(cin >> C >> S >>Q)
  {
     if( !C && !S && !Q) break;
     edges.clear();
     memset(r, 0, sizeof r);
     for(int i = 0; i < C; i++) p[i]=i;
     for(int i = 0; i < S; i++)
     {
	int c1,c2,d;
	cin >> c1 >> c2 >> d;
	edges.push_back(make_pair(d, make_pair(c1-1,c2-1)));
     } 
     kruskal();
     if(t>1)cout <<endl;
       cout << "Case #"<<t<<endl;
     for(int i = 0; i < Q; i++)
     {
	int a, b;
        cin >> a >> b;
	if( find(a-1) != find(b-1) )cout<<"no path"<<endl;
	else
        cout << query(a-1,b-1)<<endl; 
     }
     t++;
  }
  return 0;
}
