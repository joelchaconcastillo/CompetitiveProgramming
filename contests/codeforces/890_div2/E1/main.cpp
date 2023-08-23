#include <bits/stdc++.h>
using namespace std;
const int maxn=1000000;
long long ans=0;

void dfs(int _from, vector<int> &s, vector<vector<int>> &g, int p=-1){
   vector<long long> a;
   s[_from]=1;
   for(auto _to:g[_from]){
      if(_to==p)continue;
      dfs(_to, s, g, _from);
      s[_from]+=s[_to];
      a.push_back(s[_to]);
   }
   vector<long long> dp(s[_from]);
   long long cSum=0;
   for(int x:a){ ///for each subtree
      for(long long i = cSum +x; i>=0; i--){ //for each sum with lowest number of nodes to some x (a.k.a. bi)
	  for(long long pr = min(cSum, i); pr>=max(0LL, i-x); pr--){ //bigger sizes to x..
	     long long j = i-pr;
	     dp[i] = max(dp[i],dp[pr]+j*(cSum-pr)+pr*(x-j));
	  }
      }
      cSum +=x;
   }
   long long maxv = 0;
   for(auto ii:dp) maxv = max(maxv, ii);
   ans +=maxv;
   dp.clear();
   a.clear();
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
	  int n;
	  cin>>n;
	  vector<vector<int>>g(maxn);
	  vector<int>s(maxn);
	  for(int i = 1 ; i < n; i++){
		 int x;
		 cin>>x;
		 g[x-1].push_back(i);
	  }
          dfs(0,s, g);
	  cout << ans <<endl;
   return 0;
}
