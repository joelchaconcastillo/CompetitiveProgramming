#include <bits/stdc++.h>
using namespace std;
long long f(long long a, long long x){
   return int(x/a) + (x%a);
}
int main(){
   int T;
   cin>>T;
   while(T--){
     long long l, r, a, ans=0;
     cin>>l>>r>>a;
     ans = max(f(a, r), f(a, max(l, r-1)));
     long long t = r - r%a; //last period...
     ans = max(ans, f(a, max(l, t-1)));
     cout<<ans<<endl;
   }
   return 0;
}
