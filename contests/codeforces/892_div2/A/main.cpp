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
	  vector<int>a(n), b, c;
	  int minv = INT_MAX;
	  for(auto &i:a){
		  cin>>i;
		  minv = min(minv, i);
	  }
	  for(int i = 0 ; i< n ; i++){
		  if(a[i]==minv)b.push_back(minv);
		  else c.push_back(a[i]);
	  }
	  if(b.empty() || c.empty()){
		  cout << -1<<endl;
	  }
	  else{
		  cout << b.size()<<" "<<c.size()<<endl;
		  for(auto i:b)cout<<i<<" ";
		  cout<<endl;
		  for(auto i:c)cout<<i<<" ";
		  cout<<endl;
	  }
   }
   return 0;
}
