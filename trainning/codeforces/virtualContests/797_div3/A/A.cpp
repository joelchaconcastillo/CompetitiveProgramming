#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
     int n;
     cin>>n;
     int a=3,b=2,c=1, sl=(n-6)/3, rl=(n-6)%3;
     a+=sl, b+=sl, c+=sl;
     if(rl>0)a++, rl--;
     if(rl>0)b++, rl--;
     cout << b<<" "<<a<<" "<<c<<endl;
     
   }
   return 0;
}
