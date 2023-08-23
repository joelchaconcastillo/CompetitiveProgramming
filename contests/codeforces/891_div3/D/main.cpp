#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<long long> a(n), b(n);
	       vector<pair<long long, int>>c(n);
		for(int i = 0 ; i < n; i++)cin>>a[i];
		for(int i = 0 ; i < n; i++)cin>>b[i];
		for(int i = 0 ; i < n; i++)c[i]={a[i]-b[i], i};
		sort(c.begin(), c.end());
		vector<int> res;
		long long best = c.back().first;
		while(!c.empty() && best==c.back().first) res.push_back(c.back().second), c.pop_back();;
		reverse(res.begin(), res.end());
		cout <<res.size()<<endl;
		for(auto i:res)cout <<i+1<<" ";
		cout<<endl;

	}
   return 0;
}
