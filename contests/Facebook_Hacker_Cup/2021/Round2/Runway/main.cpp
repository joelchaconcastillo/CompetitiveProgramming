#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >>T;
  for(int t= 1; t<=T; t++){
   int N,M;
   cin >>N >> M;
//   multimap<int, int> models;
   multiset<pair<long long, long long> >models;
   for(int i  =0; i < M ;i++){
	   long long d;
	   cin>>d;
	   models.insert(make_pair(d, 0LL));
   }
   multiset<pair<long long, long long>> same;
   vector<long long > missing;
   long long sum=0;
   for(int i = 0; i < N ;i++){
      for(int j = 0; j < M; j++){
	long long d; 
	cin >>d;
	//auto ite = models.find(d);
	auto ite = models.lower_bound(make_pair(d, -INT_MAX));
	if(ite != models.end() && ite->first == d){
	       	same.insert(*ite);
		models.erase(ite);
	}
	else  missing.push_back(d);
      }
      auto ii=models.begin();
      for(int a = 0; a < missing.size(); a++, ii++){
	  same.insert(make_pair(missing[a], (ii->second)-1));
      }
      models=same;
      same.clear();
      missing.clear();
   }
   for(auto m:models)sum+=max(-m.second-1LL, 0LL);
   cout <<"Case #"<<t<<": "<<sum<<endl;
  }
  return 0;
}
