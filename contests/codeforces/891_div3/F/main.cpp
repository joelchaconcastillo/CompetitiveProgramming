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
		vector<long long> a(n);
		unordered_map<long long, int>f;
		for(auto &i:a)cin>>i, f[i]++;
		int q;
		cin>>q;
		for(int i = 0 ; i <q; i++){
			long long x, y;
			cin>>x>>y;
			long long num=abs(y);
			vector<long long> opt;
			opt.push_back(1);
			for(int i = 2; i <=abs(y); i++){
				long long j=i;
				while(num && num%i==0){
					num/=i;
					opt.push_back(j);
					j *=i;
				}
				if(num==0)break;
			}
			set<pair<long long, long long>>valid;
			for(auto i:opt){
			    auto n1 = i, n2 = y/i;
			    if(n1+n2!=x)continue;
			    if(f.find(n1)==f.end() || f.find(n2)==f.end())continue;
			    valid.insert({min(n1, n2), max(n1, n2)});
			}
			int cont = 0;
			for(auto ii:valid){
				int cnt1 = f[ii.first], cnt2=f[ii.second];
				if(ii.first==ii.second) cont += (cnt1*(cnt1-1)/2);
				else cont += cnt1*cnt2;
			}
			cout <<cont<< " ";
		}
		cout<<endl;
	}
   return 0;
}
