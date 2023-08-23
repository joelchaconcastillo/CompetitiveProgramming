#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      vector<int>a(n),b(n);
      for(auto &i:a)cin>>i;
      for(auto &i:b)cin>>i;
      int maxd=0;
      for(int i = 0 ; i < n ; i++) maxd=max(maxd, a[i]-b[i]);
      bool hassol=true;
      for(int i = 0 ; i < n ; i++){
        if(b[i]!=0 && maxd != (a[i]-b[i])){
	   hassol=false;
	   break;
	}
	if(b[i]==0 && maxd < a[i]){
	  hassol=false;
	  break;
	}	
      }
      if(hassol)cout<<"YES"<<endl;
      else cout << "NO"<<endl;
   }
   return 0;
}
