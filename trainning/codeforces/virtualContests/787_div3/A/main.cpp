#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
     long long a,b,c,x,y;
     cin>>a>>b>>c>>x>>y;
     x = max(x-a, 0LL);
     y = max(y-b, 0LL);
     if(x+y<= c)cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
   }
   return 0;
}
