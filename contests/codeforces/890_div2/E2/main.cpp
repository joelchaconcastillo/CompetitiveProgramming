#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
vector<int> g[maxn];
int s[maxn];
long long ans = 0;
vector<long long> b;
long long closest;
template <int len =1>
void subset_sum(int n){
   if( n>=len){
	 subset_sum<std::min(len*2, maxn)>(n);
	 return;
   }
   bitset<len> dp;
   dp[0]=1;
   for(auto x:b) dp = dp | (dp<<x);
   long long cv = n;
   closest=0;
   for(int i = 0 ; i <= n; i++){
      if( dp[i] && abs(i-(n-i))<cv){
	      closest=i;
	      cv = abs(i-(n-i));
      }
   }
}
long long solve(vector<long long> &a){
   if(a.empty()) return 0;
   sort(a.rbegin(), a.rend());
   long long cs = 0;
   for(auto x:a)cs+=x;
   if(a[0]*2>=cs)return a[0];
   int n = a.size();
   a.push_back(0);
   b.clear();
   int pi=0;
   for(int i = 1; i <=n; i++){
	   if(a[i]!=a[i-1]){
		  long long cnt = i-pi;
		  long long x = a[i-1];
		  long long j =1;
		  while(j<cnt){
			  b.push_back(x*j);
			  cnt -=j;
			  j *=2;
		  }
		  b.push_back(x*cnt);
		  pi=i;
	   }
   }
   subset_sum(cs);
   return closest;
}
void dfs(int v, int p=-1){
   vector<long long> a;
   s[v]=1;
   for(auto u:g[v]){
	   if(u==p)continue;
	   dfs(u, v);
	   s[v] += s[u];
	   a.push_back(s[u]);
   }
   long long x = solve(a);
   ans +=x*(s[v]-1-x); //S1 * (S-S1)...
   a.clear();
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i =1 ; i <n; i++){
	int x;
	cin>>x;
	g[x-1].push_back(i);
   }
   dfs(0);
   cout << ans<<endl;
   return 0;
}
