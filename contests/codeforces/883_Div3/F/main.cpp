#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   for(int t=1; t<=T; t++){
      int n;
      cin>>n;
      vector<int> a(n);
      map<int, int> f;
      for(int i = 0 ; i < n ; i++){
	  cin>>a[i];
	  f[a[i]]++;
      }
      vector<int> toRemove;
      int ans = 1;
      for(int k = 0; k < 4; k++){
	 if(n==1){
	   break;
	 }
	 cout << "- "<<toRemove.size()<<" ";
	 for(auto i:toRemove)cout << i<<" ";
	 cout<<endl;

	 vector<int> a_tmp(n);
	 map<int, int> f_tmp;
	 for(int i = 0 ; i < n; i++){
		 cin>>a_tmp[i];
		 f_tmp[a_tmp[i]]++;
	 }
	 toRemove.clear();
	 int value=-1;
	 for(auto i:f_tmp)
		 if(i.second > f[i.first]) value = i.first;
	 if(value!=-1){
	   for(int i = 0 ; i < a_tmp.size(); i++){
	      if(a_tmp[i]!=value) toRemove.push_back(i+1);
	      else ans=i+1;
	   } 
	   f.clear();
	   f[value] = f_tmp[value];
	 }
	 n -=toRemove.size();
      }
           cout << "! "<<ans<<endl;
   }
   return 0;
}
