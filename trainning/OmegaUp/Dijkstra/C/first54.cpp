#include <bits/stdc++.h>
using namespace std;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int N, M;
   cin>>N>>M;
   unordered_map<int, unordered_map<int, vector<int >>> edges;
   priority_queue<pair<int, int>>q; //{lowest time, destiny}
   for(int t = 1 ; t <= M; t++){
      int a,b;
      cin>>a>>b;
      a--, b--;
      edges[a][b].push_back(t);
      edges[b][a].push_back(t);
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
       currentDist[i]=0;
       q.push({0, i});
       while(!q.empty()){
	auto currentNeuron=q.top();q.pop();
	if(currentDist[currentNeuron.second] < -currentNeuron.first)continue;//branch and bound..
        for(auto nextNeuron:edges[currentNeuron.second]){
		if(nextNeuron.second.size()<=1)continue;
	   int toNeuron=nextNeuron.first;
	   for(int ii = 0 ; ii+1 < nextNeuron.second.size(); ii++){ //check al times that this neuron switchs..
	      if((ii%2)!=0)continue; //skip off edges
		  if(nextNeuron.second[ii+1]-1 < -currentNeuron.first)continue;
		  int totime=max(-currentNeuron.first, nextNeuron.second[ii]);//take the lowest available time
	 	  if(currentDist[toNeuron]> totime){
		     currentDist[toNeuron]= totime;
		     q.push({-totime, toNeuron});
		     break;
		  }
	   }
	}
       }
 //      for(auto ii:currentDist)cout<<ii<<" ";
 //      cout<<endl;
       for(int i=0;i<N;i++) if(currentDist[i]!=INT_MAX)dist[i]++;
   }
   for(auto i:dist)cout<<i<<endl;
   return 0;
}
