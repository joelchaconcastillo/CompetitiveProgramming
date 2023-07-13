#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t = 0 ; t < T; t++){
      int n, m, h;
     cin>>n>>m>>h;
     vector<int> place(n, 0);
     vector<pair<int, pair<int, int> >>participant(n, {0,{0, 0}}); //
     for(int i = 0 ; i < n; i++){
	vector<int> times(m);
	for(int j =0; j < m; j++){
	   cin>>times[j];
	}
	sort(times.begin(), times.end());
	int score=0, currentime=0, j=0;
	while(j<m && currentime+times[j] < h){
	   currentime +=times[j];
	   score +=currentime;
	   j++;
	}
	participant[i]={j, {score, i}};
     } 
     sort(participant.begin(), participant.end());
     int k = 1;
     for(auto i:participant) place[i.second.second]=k++;
     cout << place[0]<<endl;

   }
   return 0;
}
