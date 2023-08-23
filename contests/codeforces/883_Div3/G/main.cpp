#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int T;
   cin>>T;
   for(int t = 1; t <=T; t++){
      int n, m ;
      cin>>n>>m;
      unsigned long long state;
      bitset<10>tmp;
      cin>>tmp;
      state = tmp.to_ulong();
      vector<pair<unsigned long long, pair<unsigned long long, unsigned long long> > > data(m);
      for(int i = 0; i < m; i++){
	 cin>>data[i].first;
	 cin >> tmp;
	 data[i].second.first = ((1<<n)-1)^tmp.to_ulong();
	 cin >> tmp;
	 data[i].second.second = tmp.to_ulong();
      }
      set<pair<unsigned long long, unsigned long long>> q;
      vector<int> dist(1<<n, INT_MAX);
      dist[state]=0;
      q.insert({0, state});
      while(!q.empty()){
	   auto current = *q.begin();
	   q.erase(q.begin());
	   for(int i = 0; i <  m; i++){
	      int attempt =  current.first + data[i].first;
	      unsigned long long to = (current.second & data[i].second.first) | data[i].second.second;
	      if(dist[to] > attempt){
		q.erase({dist[to], to});
		dist[to] = attempt;
		q.insert({attempt, to});
	      }
	   }
      }
      if(dist[0]==INT_MAX) cout << -1<<endl;
      else cout << dist[0]<<endl;
   }
   return 0;
}
