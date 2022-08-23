#include<bits/stdc++.h>
using namespace std;
int main(){
   string st;
   map<int, string> res;
   int maxl=0;
   while(getline(cin, st)){
      int n = st.size();
      for(int i = 0 ; i < n; i++){
	  res[i].push_back(st[i]);
      }
      for(int i = n; i<100; i++)
	  res[i].push_back(' ');
      maxl=max(maxl, n);
   }
   for(int i = 0; i<maxl; i++){
      while(!res[i].empty()){
	cout<<res[i].back();
	res[i].pop_back();
      }
      cout<<endl;
   }
   return 0;
}
