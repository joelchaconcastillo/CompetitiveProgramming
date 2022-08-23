#include <bits/stdc++.h>
#define MAX_N 500
using namespace std;
int S, P;
int x[MAX_N], y[MAX_N], p[MAX_N], r[MAX_N], NEdges;
//vector<pair<double, pair<int, int> > > edges;
pair<double, pair<int, int> > edges[MAX_N*MAX_N];
double dist(int a, int b){return sqrt((x[a]-x[b])*(x[a]-x[b]) +  (y[a]-y[b])*(y[a]-y[b]));} 
int find(int n){return (n==p[n])?n:(p[n]=find(p[n]));}
void unionf(int a, int b)
{
   a = find(a), b=find(b);
   if(r[a] > r[b]) p[b]=a;
   else
   {
	p[a]=b;
 	if(r[a] == r[b]) r[b]++;
   }
}
double partial_kruskal()
{
   NEdges=0;
   for(int i = 0; i < P; i++)
   {
      r[i]=0, p[i]=i;
      for(int j = i+1; j < P; j++)
	{
//	edges.push_back(make_pair(dist(i, j), make_pair(i,j)));
	  edges[NEdges++]=(make_pair(dist(i, j), make_pair(i,j)));
	}
   }
   //sort(edges.begin(), edges.end()); 
   sort(edges, edges+NEdges); 
   int Ncomponents=P;
   double maxcost = -1;
//   for(auto idx:edges)
   for(int i = 0; i < NEdges; i++)
   {
	auto idx = edges[i];
      if(find(idx.second.first) != find(idx.second.second))
	{
	   unionf(idx.second.first, idx.second.second);
	   maxcost = max(maxcost, idx.first);
	   Ncomponents--;
	} 
     if(Ncomponents == S) break;
   }
  return maxcost;
}
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
     cin >> S >> P;
 //   edges.clear();
     for(int i = 0 ; i < P; i++)
     {
	cin >> x[i] >> y[i];
     }     
     cout << fixed<<setprecision(2) << partial_kruskal()<<endl;
  } 
  return 0;
}
