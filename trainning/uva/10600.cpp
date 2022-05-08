#include <bits/stdc++.h>
#define MAX_N 300
using namespace std;
int N, M;
int p[MAX_N], r[MAX_N];
vector<pair<int, pair<int, int> > > edges;
vector<int> enabled;
vector<int> selected_edges;
int find(int n){return (n==p[n])?n:(p[n] = find(p[n]));}
void unions(int a, int b)
{
  a = find(a), b = find(b);
  if( r[a] > r[b]) p[b] = a;
  else
  {
     p[a] = b;
     if(r[a] == r[b]) r[b]++;
  }
}
int kruskal(bool flag)
{
   for(int i = 0; i < N; i++) p[i] =i, r[i]=0;
   int totalsum = 0,  cont = 0, nSelected=1;
   for(auto idx:edges)
   {
	if( enabled[cont] && find(idx.second.first) != find(idx.second.second))
	{
	   unions(idx.second.first, idx.second.second);
	   nSelected++;
	   totalsum += idx.first;
	   if(flag)
	   {
            selected_edges.push_back(cont)	;
	   }
	}
    cont++;
	if(nSelected == N) break;
   } 
   if(nSelected < N) return INT_MAX;
   return totalsum;
}
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
     cin >> N >> M ;
     selected_edges.clear();
     enabled.assign(M, true);
     edges.clear();
     for(int i = 0; i < M ; i++)
     {
	int ai, bi, ci;
       cin >> ai >>bi>> ci;
       edges.push_back(make_pair(ci, make_pair(bi-1, ai-1)));
     } 
     int best1, best2 = INT_MAX;

     sort(edges.begin(), edges.end());
     best1 = kruskal(true);   
     for(int i = 0; i < selected_edges.size(); i++)
     for(auto idx:selected_edges)
     {
	enabled[idx] = false;
	best2 = min(best2, kruskal(false));
	enabled[idx] = true;
     } 
     cout << best1 << " " << best2<<endl;
  }
  return 0;
}

