#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
     long long g, l, p, sol=0;
     cin>>g>>l;
     p=g*l;
     for(long long a=g; a<=l; a+=g){
	if(p%a)continue;
       long long b=(g*l)/a;
       long long gc=__gcd(a,b);
       if( gc==g && a*b/gc == l){
	  sol=a; break;
       }
     }
     if(sol)cout<<sol<<" " <<p/sol<<endl;
     else cout <<-1<<endl;
   }
   return 0;
}
