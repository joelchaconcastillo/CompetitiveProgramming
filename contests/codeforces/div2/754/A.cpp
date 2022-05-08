#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin >>T;
   while(T--){
     long long a1, a2, a3;
     cin>>a1>>a2>>a3;
     long long y=a1+a3-2LL*a2, z2=y/3LL;
     long long z1=z2-1, z3=z2+1;
     long long s= min(llabs(y-3LL*z1), llabs(y-3LL*z2));
     s= min(s, llabs(y-3LL*z3));
     cout << s<<endl;

     
   }
   return 0;
}
