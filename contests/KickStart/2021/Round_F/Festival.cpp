#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin>>T;
  for(int t =1; t<=T; t++){
    int D, N, K;
    vector<pair<int, pair<int,int> > > data;
    map<int, multiset<long long> >points;
    cin >>D>>N>>K;
    long long maxd=0;
    for(int i = 0; i < N; i++){
      int hi, si, ei;
      cin >> hi>>si>>ei;
      points[si]=multiset<long long>();
      points[ei]=multiset<long long>();
      data.push_back(make_pair(si, make_pair(ei, hi)));
    }
    for(int i = 0; i < data.size(); i++)
    {
	    auto p=points.lower_bound(data[i].first);
        for(; p!= points.end(); p++){
          if(p->first >= data[i].first && p->first <=data[i].second.first)
            p->second.insert(-data[i].second.second);
	  if(data[i].first > p->first)break;
	  if(data[i].second.first < p->first)break;
      }
    }
    for(auto &p:points){
        int k=0;
        long long ss=0;
        for(auto &i:p.second){
            if(k>=K)break;
            ss+= (-i);
            k++;
        }
        maxd=max(maxd, ss);
    }
    cout <<"Case #"<<t<<": "<< maxd<<endl;
  }
  return 0;
}
