#include <bits/stdc++.h>
//#define int long long
using namespace std;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
      int n, k;
      cin>>n>>k;
      string s;
      cin>>s;
      vector<vector<int>>pref(n+1, vector<int>(n+1));
      auto suf=pref;
      for(int l = 0 ;  l < n; l++){
	 int cnt1=0;
	 for(int r = l+1; r<=n; r++){
	    cnt1 += s[r-1]=='1';
	    pref[r][cnt1]=max(pref[r][cnt1], r-l);
	    suf[l][cnt1]=max(suf[l][cnt1], r-l);
	 }
      }
      for(int r = 0; r<=n; r++){
	 for(int cnt = 0; cnt <=n; cnt++){
	    if(r) pref[r][cnt] = max(pref[r][cnt], pref[r-1][cnt]);
	    if(cnt) pref[r][cnt] = max(pref[r][cnt], pref[r][cnt-1]);
	 }
      }
      for(int l = n ; l>=0; l--){
	 for(int cnt = 0; cnt <=n; cnt++){
	    if(l+1<=n) suf[l][cnt] = max(suf[l][cnt], suf[l+1][cnt]);
	    if(cnt) suf[l][cnt] = max(suf[l][cnt], suf[l][cnt-1]);
	 }
      }
      vector<long long> ans(n+1, -INT_MAX);
      vector<long long>dp(n+1, -INT_MAX);
      for(int l = 0; l < n; l++){
	 int cnt0=0;
	 for(int r=l; r<=n; r++){
	    if(r>l)cnt0 +=s[r-1]=='0';
	    if(cnt0>k)break;
	    dp[r-l] = max(dp[r-l], (long long) pref[l][k-cnt0]);
	    dp[r-l] = max(dp[r-l], (long long) suf[r][k-cnt0]);
	 }
      }
      for(long long i = 0 ; i <=n; i++)
	 for(long long a = 1; a<=n; a++) ans[a] = max(ans[a], i+dp[i]*a);
      for(int i = 1; i<=n; i++)cout<<ans[i]<<" ";
      cout<<endl;

   }
   return 0;
}
