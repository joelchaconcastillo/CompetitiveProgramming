#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
     string st, ss;
     cin>>st>>ss;
     bool found=false;
     int n=st.size();
     for(int i = 0 ; i < n ; i++){
	if(st[i]==ss.front() && i%2==0){
		found=true;
		break;
	}
     }
     if(found)cout<<"YES"<<endl;
     else cout <<"NO"<<endl;
   }
   return 0;
}
