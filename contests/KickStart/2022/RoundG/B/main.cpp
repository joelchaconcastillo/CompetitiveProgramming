/*
 T
 Rs Rh
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin>>T;
  for(int t=1;t <=T; t++){
      int rs, rh, N;
      cin>>rs>>rh>>N;
      vector<pair<long long, int>> D;
      long long maxdist = (rs+rh)*(rs+rh);
      for(int i = 0 ; i < N; i++){ //red
         long long x, y;
         cin>>x>>y;
         long long dist = x*x+y*y;
         if(dist <= maxdist) D.push_back({dist, 0});
      }
      int M;
      cin>>M;
      for(int i = 0 ; i < M; i++){
         int x, y;
         cin>>x>>y;
         long long dist=x*x+y*y;
         if(dist <= maxdist) D.push_back({dist, 1});
      }
      sort(D.begin(), D.end());
      int idx = 0;
      vector<int> scores(2,0);
      while(idx < D.size() && D[idx].second == D.front().second) scores[D[idx].second]++, idx++;
      cout <<"Case #"<<t<<": "<< scores[0]<<" "<<scores[1]<<endl;
  }
  return 0;
}
