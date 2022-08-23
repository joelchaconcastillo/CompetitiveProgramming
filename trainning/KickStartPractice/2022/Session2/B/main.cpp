#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   for(int t=1; t <=T; t++){
     long long L, R;
     cin>>L>>R;
     long long res= min(L,R);
     res=(res*(res+1))/2;
     cout<<"Case #"<<t<<": "<<res<<endl;
   }
   return 0;
}
