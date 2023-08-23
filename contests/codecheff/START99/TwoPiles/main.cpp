#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
     int n;
     cin>>n;
     vector<pair<int, int> >all;
     int M=-1e9;
     for(int i = 0 ; i< n; i++){
	int a, b;
	cin>>a>>b;
	all.push_back({a, i});
	all.push_back({b, i});
	M = max(M, min(a,b));
     }
     sort(all.begin(), all.end());
     int ans = 1e9;
     for(int i = 0; i+1 <all.size(); i++){
	if(all[i].second == all[i+1].second)continue;
	if(all[i].first < M && all[i+1].first < M)continue;
	ans = min(ans, all[i+1].first-all[i].first);
     }
     cout << ans<<endl;
   }
   return 0;
}
