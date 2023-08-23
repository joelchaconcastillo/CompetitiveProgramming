#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int, int> >a(n);
		for(int i = 0 ; i<  n; i++){
		   cin>>a[i].first;
		   a[i].second=i;
		}
		vector<int> dpl(n,0), dpr(n,0);
		sort(a.begin(), a.end());
		int c1 = 0;
		for(int i = 1 ; i < n; i++){
			c1 += i*(a[i].first-a[i-1].first);
			dpr[i] = c1;
		}
		c1=0;
		for(int i = n-2, j=1; i >= 0; i--, j++){
			c1 += j*(a[i+1].first-a[i].first);
			dpl[i] = c1;
		}
		vector<int>res(n,0);
		for(int i = 0 ; i < n ;i++){
			res[a[i].second]+=dpl[i];
			res[a[i].second]+=dpr[i];
			res[a[i].second]+=n;
		}
		for(auto i:res)cout <<i <<" ";
		cout<<endl;

	}

   return 0;
}
