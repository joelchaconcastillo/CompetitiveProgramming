#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
     int n, m;
     cin>>n>>m;
     vector< pair<int, pair<int, int> > > data(m);
     for(int i = 0; i < m; i++){
	     cin>>data[i].second.first>>data[i].first; 
	     data[i].second.second=i; 
     }
     sort(data.begin(), data.end());
     while(data.size()>2*n)data.pop_back();
     vector<pair<int, int>> data2;
     long long sum=0;
     for(auto i:data) data2.push_back({i.second.first,i.second.second}), sum+=i.first;
     sort(data2.begin(), data2.end());
     int l=0, r=data2.size()-1;
     cout<<sum<<endl;
     while(l<r) cout << data2[l++].second+1 <<" " <<data2[r--].second+1<<endl;
     cout<<endl;

   }
   return 0;
}
