#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
int x[MAX_N], y[MAX_N];
int p[MAX_N], r[MAX_N];
int N, M;
vector<pair<int, int> > newbeste;
int find(int a){ return (p[a] == a)?a:(p[a]=find(p[a]));}
bool cmp( pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){ return a.first < b.first;}
int unionf(int a, int b)
{
  int pa=find(a), pb = find(b);
  if(pa==pb) return 0;
  if(r[pa] > r[pb]) p[pb]=pa;
  else
  {
     p[pa] = p[pb];
    if(r[pa] == r[pb]) r[pb]++;
  }
  return 1;
}
int dist(int a, int b)
{
   return (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
}
void kruskal()
{
   for(int i = 0; i < N ; i++) {p[i]=i;r[i]=0;}
   vector< pair< int, pair<int, int> > > edges; 
   int s = 0;
   for(int  i =0 ; i < M ; i++)
   {
      int a, b;
      cin >> a >>b;
      s += unionf(a-1, b-1);
   }
   for(int i = 0; i <  N; i++)
   {
     for(int j = i+1; j <  N; j++)
     {
	edges.push_back(make_pair(dist(i,j), make_pair(i,j)));
     }
   }    
   sort(edges.begin(), edges.end(), cmp);
   for(int idx = 0; idx < edges.size(); idx++)
   {
      int i = edges[idx].second.first, j = edges[idx].second.second;
      if( find(i) != find(j)) 
	{
	   unionf(i, j);
	   cout << i+1 << " " <<j+1<<endl;
	}
   }
 
   if(s == N-1 ) cout << "No new highways need"<<endl; 
}
int main()
{
  int t;
  cin>>t;
  for(int o = 0; o < t; o++)
  {
    newbeste.clear();
    cin >>N;
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
    cin >> M;
    kruskal();
    for(int i = 0; i < newbeste.size(); i++) cout << newbeste[i].first+1 << " " <<newbeste[i].second+1<<endl;
    if(o<t-1)
    cout << endl;
  }
  return 0;
}
