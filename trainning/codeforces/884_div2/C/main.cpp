#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t =1 ; t <= T; t++){
	   int n;
	   cin >> n;
	   n+=2;
	   vector<long long> dat(n, 0);
	   vector<int> l(n, -1), r(n, -1);
	   priority_queue<pair<long long, int>> q;
	   for(auto &i:dat)cin>>i;
	   for(int i = 1 ; i <= n; i++)cin>>dat[i];
	   for(int i = 1 ; i <= n ; i++){
		  l[i] = i-1;
		  r[i] = i+1;
		  q.push({-dat[l[i]]-dat[r[i]]+dat[i], i});
	   }
	   vector<bool>marked(n, false);
	   while(q.size()>1){
		 auto ii = q.top(); q.pop();
	   }
	   cout <<q.top().first<<endl;
   }
   return 0;
}
