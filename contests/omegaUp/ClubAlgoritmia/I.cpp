#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*map<pair<int, int>, pair<int, vector<int> > >memo;

pair<int, vector<int>> dp(int i, vector<int> &w, int rem, vector<int> path){
  if(rem < 0 || i>=w.size() )return {INT_MAX, vector<int> ()};
  pair<int, int> pp = {i, rem};
//  if(memo.find(pp)!= memo.end())return memo[pp];
  int n = w.size();
  pair<int, vector<int>>res({rem, path});

  for(int j = i; j < n; j++){
    if(rem-w[j]<0) continue;
    if(!path.empty() && j-path.back() <=1 )continue;
    path.push_back(j);
    auto current = dp(j+1, w, rem-w[j], path);
    path.pop_back();
    res = min(res, current);
  }
  return res;
}*/
int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N, C;
  cin>>N>>C;
  vector<int> w(N);
  for(int i = 0 ; i <N; i++){
    cin>>w[i];
  }
  if(C == 0 || N == 0){
	  cout <<0<<endl<<endl;
	  return 0;
  }
  /*auto res = dp(0, w, C, vector<int>());
  cout <<C-res.first<<endl;
  for(auto i:res.second) cout<<i<<" ";
*/

  vector<int> dp(N, INT_MAX), leftIndex(N, -1);
  for(int i = 0 ; i < N; i++){
    dp[i] = C-w[i];
  }
  int minR=C;
  for(int i = 0; i < N; i++){
    pair<int, int> minc({dp[i], i});
    for(int j = 0; j+1 < i; j++){
      int diff = dp[j]-w[i];
      if(diff < 0) continue;
      if(minc.first > diff){
        minc = {diff, j};
      }
    }
    dp[i] = minc.first;
    minR=min(minc.first, minR);
    leftIndex[i] = minc.second;
  }
  vector<int>minSeq;
  for(int i = 0 ; i < N; i++)minSeq.push_back(INT_MAX);
 for(int i = 0 ; i < N; i++){
    if(dp[i]!=minR)continue;
	 vector<int> seq;
	 seq.push_back(i);
	 while(seq.back()!=leftIndex[seq.back()]){
		 seq.push_back(leftIndex[seq.back()]);
	 }
	 reverse(seq.begin(), seq.end());
	 minSeq = min(minSeq, seq);
 }
  cout << C-minR<<endl;
   for(auto i:minSeq)cout << i<<" ";
  cout<<endl;

  return 0;
}
