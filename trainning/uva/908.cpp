#include <bits/stdc++.h>
using namespace std;
int N, K, M;
vector<int> p, r;
vector< tuple<int, int, int> > Edges;
int find(int c){ return (c==p[c])? c:(p[c]=find(p[c])); }
void uniond(int a, int b)
{
  int pa = find(a), pb = find(b);
  if(pa==pb) return;
  if(r[pa] > r[pb]) p[pb] = pa;
  else
  {
     p[pa] = pb;
     if(r[pa] == r[pb])
	r[pb]++;
  }
}
int kruskal()
{
  sort(Edges.begin(), Edges.end());
  int idx = 0, cont = 2;
  int totalcost = 0;
  uniond(get <1> (Edges[idx]), get <2> (Edges[idx]));
  totalcost += get <0> (Edges[idx]);
  idx++;
  while(cont < N && idx < K+M)
  {
     if( find(get<1> (Edges[idx])) != find(get<2> (Edges[idx])))
     {

       uniond(get <1> (Edges[idx]), get <2> (Edges[idx]));
        totalcost += get<0>(Edges[idx]);
	cont++;
     }
     idx++;
  }
  return totalcost;
}
int main()
{
 int it=0;
  while(cin >> N)
  {
  if(it++>0)cout <<endl;
    Edges.clear();
    p.assign(N,0);
    r.assign(N,0);
     int prev_cost = 0;
     for(int i = 0; i < N-1; i++)
     {
	int a, b, w;
 	cin >> a >>b >> w;
	prev_cost +=w;
     }
     cin >> K;
     for(int i = 0; i < K; i++)
     {
	int a, b, w;
 	cin >> a >>b >> w;
	Edges.push_back(make_tuple(w, a-1, b-1));
     }
     cin >> M;
     for(int i = 0; i < M; i++)
     {
	int a, b, w;
 	cin >> a >>b >> w;
	Edges.push_back(make_tuple(w, a-1, b-1));
     }
    for(int i = 0; i < N; i++) p[i] = i;
    cout << prev_cost<<endl;    
    cout << kruskal()<<endl;
  }
  return 0;
}
