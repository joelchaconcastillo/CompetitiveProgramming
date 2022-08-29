#include <bits/stdc++.h>
using namespace std;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int T, N, M, Q;
   cin>>T;
   for(int t=1;t<=T;t++){
      cin>>N>>M>>Q;
      vector<pair<int, pair<int, long long> > >listEdges(M);
      for(int i = 0; i < M; i++){
         cin >> listEdges[i].first>>listEdges[i].second.first>>listEdges[i].second.second;
      }
      cout<<"Case #"<<t<<": ";
      vector<pair<int, int> > request(Q);
      vector<bool> used(N+1, false);
      for(int i = 0; i < Q; i++){
	  cin>>request[i].first>>request[i].second;
	  used[request[i].first]=used[request[i].second]=true;
       }
      unordered_map<int, unordered_map<int, long long> > adj;
      for(auto edge:listEdges){
        if(!used[edge.first] && !used[edge.second.first]) continue;
        adj[edge.first][edge.second.first]=edge.second.second;
        adj[edge.second.first][edge.first]=edge.second.second;
      }
       unordered_map<int, unordered_map<int, long long> > memo;
       for(int i = 0; i < Q; i++){
          int from=request[i].first, to=request[i].second;
	  if(memo.find(from) != memo.end() && memo[from].find(to)!=memo[from].end()){
	     cout<<memo[from][to]<<" ";
	     continue;
 	  }
          long long totalCap=2LL*adj[from][to];
          for(auto &next:adj[from]){
	     long long minc=next.second;
	     if(adj[next.first].find(to)==adj[next.first].end())continue;
             minc=min(minc, adj[next.first][to]);
	     totalCap+=minc;
	  }
	  memo[from][to]=totalCap;
	  memo[to][from]=totalCap;
	  cout<<totalCap<<" ";
       } 
       cout<<endl;
 	cerr<<t<<" "<<N<<" "<<M<<" "<<Q<<endl;
   }
   return 0;
}
