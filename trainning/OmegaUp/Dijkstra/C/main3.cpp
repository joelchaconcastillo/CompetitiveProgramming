#include <bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int N, M;
   cin>>N>>M;
   unordered_map<int, unordered_map<int, vector<int >>> edges;
   priority_queue<pair<int, int>>q; //{lowest time, destiny}
   vector<int> minOutTime(N, INT_MAX);
   for(int t = 1 ; t <= M; t++){
      int a,b;
      cin>>a>>b;
      a--, b--;
      edges[a][b].push_back(t);
      edges[b][a].push_back(t);
      minOutTime[a]=min(minOutTime[a], t);
      minOutTime[b]=min(minOutTime[b], t);
   }
   for(auto &ii:edges){
      for(auto &jj:ii.second){
	 jj.second.push_back(M+1);
      }
   }
   vector<int> dist(N,0);
   for(int i=0;i<N;i++){
       vector<int> currentDist(N, INT_MAX);
       priority_queue<pair<int, int>> q;
       if(minOutTime[i]==INT_MAX){
	       dist[i]=1;
	       continue;
       }
       currentDist[i]=minOutTime[i];
       q.push({-currentDist[i], i});
       while(!q.empty()){
	int time=-q.top().first, id=q.top().second;
	q.pop();
	if(currentDist[id] < time)continue;//branch and bound..
        for(auto nextNeuron:edges[id]){
	   int toNeuron=nextNeuron.first;
	   int idx=upper_bound(nextNeuron.second.begin(), nextNeuron.second.end(), time)-nextNeuron.second.begin();
	   idx--;
	   if(idx<0 || (idx%2==1) ) idx++;
	   if(idx>=nextNeuron.second.size()-1)continue;
	   int totime= max(time, nextNeuron.second[idx]);
	   if(currentDist[toNeuron]>totime){
	           currentDist[toNeuron]=totime;
	           q.push({-totime, toNeuron});
	   }
	}
       }
       for(int i=0;i<N;i++) if(currentDist[i]!=INT_MAX)dist[i]++;
   }
   for(auto i:dist)cout<<i<<endl;
   return 0;
}
