#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t=1; t<=T; t++){
	   int n, k;
	   cin>>n>>k;
	   vector<int> dp(k+1, 0);
	   vector<priority_queue<int> > pqc(k+1);
	   vector<unordered_map<int, int>>freq(k+1);

	   for(int i = 1 ;i <= n; i++){
	      int color; cin>>color;
	      int diff = i-dp[color]-1;
	      pqc[color].push(diff);
	      dp[color]=i;
	      freq[color][diff]++;
	   }
	   for(int i = 1 ; i <= k; i++){
	      int diff = n-dp[i];
	      pqc[i].push(diff);
	      dp[i]=n;
	      freq[i][diff]++;
	   }
	   int minv=INT_MAX;
	   for(int i = 1 ; i <= k; i++){
	      if(pqc[i].empty())continue;
	      auto v = pqc[i].top();
	      pqc[i].pop();
	      if(pqc[i].empty())continue;
	      pqc[i].push(v/2);
	      minv = min(minv, pqc[i].top());
	   }
	   cout << minv<<endl;
   }
   return 0;
}
