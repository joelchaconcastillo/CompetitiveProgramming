#include <bits/stdc++.h>
using namespace std;
vector<vector<bool> > H;
vector<vector<int>> adj;
void dfs(int node, vector<int> path){
  path.push_back(node);
  if( path.size() == 9){
	  for(auto i:path)cout<<i+1;
	  cout<<endl;
	  return;
  }
  for(auto edge:adj[node]){
     if(H[node][edge] || H[edge][node] ) continue;
     H[node][edge]=1;
     dfs(edge, path);
     H[node][edge]=0;
  }
}
int main(){
   H.assign(5, vector<bool>(5, false));
   adj.push_back({1, 2, 4});
   adj.push_back({0, 2, 4});
   adj.push_back({0, 1, 3, 4});
   adj.push_back({2, 4});
   adj.push_back({0, 1, 2, 3});
   dfs(0, {});
   return 0;
}
