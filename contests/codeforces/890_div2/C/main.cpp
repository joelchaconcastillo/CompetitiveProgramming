#include <bits/stdc++.h>
using namespace std;
bool can(vector<int> &a, int id, long long what, int k){
   if(id>=a.size())return false;
   if(k<0)return false;
   if(a[id]>=what)return true;
   long long used = max(what-a[id], 0LL);
   return can(a, id+1, what-1, k-used);
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
	  int n, k;
	  cin>>n>>k;
	  vector<int>a(n);
	  for(int i = 0 ; i < n ; i++) cin>>a[i];
	  long long ans = 0;
	  for(int i = 0 ; i < n; i++){
	     long long lo = 0, hi = 1e9;
	     while(lo<hi){
		 long long mid = (lo+hi+1)/2;
		 if(can(a, i, mid, k)) lo=mid;
		 else hi=mid-1;
	     }
	     ans = max(ans, lo);
	  }
	  cout << ans <<endl;
   }
   return 0;
}
