#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>edges;
vector<int> inD, outD, dp;
int calc(int v){
   if(dp[v] !=-1)return dp[v];
   if(inD[v]>=2 && outD[v]>=2){
    dp[v]=1;
    for(auto u:edges[v]) dp[v]=max(dp[v], calc(u)+1);
   }else if(inD[v]>=2) dp[v]=1;
   else dp[v]=-INT_MAX;
   return dp[v];
}
int main(){
   cin>>n>>m;
   edges.assign(n, vector<int>());
   inD.assign(n, 0);
   outD.assign(n, 0);
   for(int i =  0 ; i < m; i++){
     int v, u;
     cin>>v>>u;
     v--,u--; 
     edges[v].push_back(u);
     inD[u]++, outD[v]++;
   }
   int ans=1;
   dp.assign(n, -1);
   for(int v=0;v <n; v++){
	if(outD[v]>=2){
	  for(auto u:edges[v]){
	      ans=max(ans, calc(u)+1);
	  } 
	}
   }
   cout<<ans<<endl;
   return 0;
}
