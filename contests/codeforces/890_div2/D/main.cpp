#include <bits/stdc++.h>
using namespace std;
int q(int l, int r){
   if(l==r) return 0;
   cout << "? "<<l+1<<" "<<r+1<<endl;
   int res;
   cin>>res;
   return res;
}
int solve(int l, int r){
   if(l==r){
     return l;
   }
   int m = (l+r)/2;
   int a = solve(l, m), b = solve(m+1, r);
   int r1=q(a, b-1), r2=q(a, b);
   if(r1==r2)return b;
   return a;
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
      int n;
      cin>>n;
      auto r = solve(0, n-1);
      cout << "! "<<r+1<<endl;
   }
   return 0;
}
