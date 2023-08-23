#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<vector<int>> edge_to(n);
  for(int i = 0 ; i < n ; i++){
    int m;
    cin>>m;
    for(int j = 0 ; j < m; j++){
      int to;
      cin>>to;
      edge_to[i].push_back(to);
    }
  }

  queue<pair<int, int> > q;
  int source;
  cin>>source;
  if(edge_to[source].empty()){
	  cout << 0 <<endl;
	  return 0;
  }
  vector<bool> marked(n, false); 
  vector<int> freqJump(n, 0);
  q.push({source, 0});
  while(!q.empty()){
    auto current = q.front(); q.pop();
    int idx = current.first;
    if(marked[idx])continue;
    marked[idx] = true;
    freqJump[current.second]++;
    for(auto _to:edge_to[idx]){
      if(marked[_to])continue;
      q.push({_to, current.second+1});
    }
  }
  pair<int, int> maxv(0,0);
  for(int i = 0 ; i < n; i++) maxv = max(maxv, {freqJump[i], -i});
  cout <<maxv.first<<endl;
  return 0;
}
