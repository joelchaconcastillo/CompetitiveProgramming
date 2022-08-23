#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>edges;
int main(){
   int T;
   cin>>T;
   for(int t=1; t<=T; t++){
     int n, m, s,e;
     cin>>n>>m>>s>>e;
     edges.assign(n, vector<pair<int,int>>());
     for(int i=0; i <m; i++){
	 int u,v,w;
	 cin>>u>>v>>w;
	 edges[u].push_back(make_pair(v, w));
	 edges[v].push_back(make_pair(u, w));
     }
     vector<int>dist(n, INT_MAX);
     dist[s]=0;
     priority_queue<pair<int, int> > q;
     q.push({0, s});
     while(!q.empty()){
	auto node=q.top(); q.pop();
	if(-node.first>dist[node.second])continue;
	for(auto to:edges[node.second]){
		if(dist[to.first] > to.second+dist[node.second]){
	 	   dist[to.first]=dist[node.second]+to.second;
		   q.push({-dist[to.first], to.first});
		}
	}
     }
     cout<<"Case #"<<t<<": ";
     if(dist[e]==INT_MAX)cout<<"unreachable"<<endl;
     else
     cout<<dist[e]<<endl;
   }
   return 0;
}
