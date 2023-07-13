#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
	   if(t>1)cout<<endl;
      int D;
      cin>>D;
      vector< pair<int, pair<int, string>>> records(D);
      for(int i = 0 ; i < D; i++){
	      cin>>records[i].second.second >> records[i].first>>records[i].second.first;
      }
      sort(records.begin(), records.end());
      int Q;
      cin>>Q;
      for(int i = 0; i < Q; i++){
	      int look;
	    cin>>look;
	    vector<string>res;
	    for(auto item:records){
		    if(item.first <= look&& item.second.first >= look)
			    res.push_back(item.second.second);
	    }
	    if(res.empty() || res.size()>1) cout <<"UNDETERMINED"<<endl;
	    else cout << res.front()<<endl;
      }
   }
   return 0;
}
