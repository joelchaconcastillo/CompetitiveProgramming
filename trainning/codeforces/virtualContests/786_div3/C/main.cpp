#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
     string s, t;
     cin>>s>>t;
     long long countA=0;
     for(auto i:t) countA+=(i=='a')?1:0;
     long long T=t.size(), S=s.size(), sol=1LL<<S;
     if(T==1){
       if(countA==1) cout<<1<<endl;
       else cout<<sol<<endl;
     }else{
	if(countA==0) cout<<sol<<endl;
	else cout<<-1<<endl;
     }
    }
   return 0;
}
