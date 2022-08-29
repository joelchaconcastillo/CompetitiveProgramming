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
      unordered_map<int, unordered_map<int, long long> > adj;
      for(int i = 0; i < M; i++){
	 int from, to; long long W;
	 cin>>from>>to>>W;
	 adj[from][to]=W;
	 adj[to][from]=W;
      }
      cout<<"Case #"<<t<<": ";
      unordered_map<int, unordered_map<int, long long> > memo;
      for(int i = 0; i < Q; i++){
	  int from, to;
	  cin>>from>>to;
	  if(adj[from].size()>adj[to].size())swap(from, to);
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
