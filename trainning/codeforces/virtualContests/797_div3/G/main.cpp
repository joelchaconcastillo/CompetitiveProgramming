#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
    int n, m;
    cin>>n>>m;
    vector<int> data(n);
    set<int> formed;
    for(int i = 0; i < n ; i++){
	cin>>data[i]; 
	if(formed.empty() || data[*formed.rbegin()] > data[i])
		formed.insert(i);
    }
    for(int i = 0 ; i < m ; i++){
      int id, d;
      cin>>id>>d;
      id--;
      formed.erase(id);
      data[id]-=d;
      auto it = formed.upper_bound(id);
      if(it!=formed.begin()){
	      auto pit=prev(it);
	      if(data[*pit] > data[id]) formed.insert(id);
      }
      else formed.insert(id);
      while(true){
	auto it=formed.upper_bound(id);
	if(it!= formed.end() && data[*it]>=data[id]) formed.erase(it);
	else break;
      }
      cout<<formed.size()<<" ";
    }
    cout<<endl;
   }
   return 0;
}
