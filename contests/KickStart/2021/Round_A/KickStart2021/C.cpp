#include <bits/stdc++.h>
using namespace std;
long long g[300*300];
bool visited[300*300];
int offsi[] = {0, -1, 0, 1};
int offsj[] = {-1, 0, 1, 0};
int main()
{
  int it;
  cin>>it;
  for(int t = 1; t <= it; t++)
  {
     memset(visited, 0, sizeof visited);
     int R, C;
     cin>>R >> C;
     set<pair<int, int>> buckets;
     for(int i = 0; i < R; i++)
     {
       for(int j = 0; j < C; j++)
       {
	  cin>> g[i*C+j];
	  buckets.insert(make_pair(-g[i*C+j], i*C+j));
       }
     }
     long long to = 0;
     while(!buckets.empty())
     {
	int node = buckets.begin()->second;
	buckets.erase(buckets.begin());
	 if(visited[node]) continue;
	visited[node]=true;
	int i = node/C, j = node%C;
	for(int k = 0; k < 4; k++)
	{
	   int i2 = i+offsi[k], j2 = j+offsj[k];
	   if(visited[i2*C+j2]) continue;
	   if( i2 <0 || i2 >=R) continue;
	   if( j2 <0 || j2 >=C) continue;
	   if( g[i*C+j]-g[i2*C+j2]<=1) continue;
	   buckets.erase(make_pair(-g[i2*C+j2],i2*C+j2));
	   to +=(g[i*C+j]-g[i2*C+j2]-1);
	   g[i2*C+j2] += (g[i*C+j]-g[i2*C+j2]-1);
	   buckets.insert(make_pair(-g[i2*C+j2], i2*C+j2));
	}
     }
     cout << "Case #"<<t<<": "<<to<<endl;
  }
  return 0;
}
