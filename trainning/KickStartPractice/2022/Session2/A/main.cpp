#include <bits/stdc++.h>
using namespace std;
int main(){
   int T,n,m;
   cin>>T;
   for(int t=1;t<=T;t++){
     cin>>n>>m;
     long long sum=0, ans=0;
     for(int i = 0 ;  i < n; i++) cin>>ans, sum+=ans;
     sum%=m;
     cout<<"Case #"<<t<<": "<<sum<<endl;
   }
   return 0;
}
