#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
     int n;
     cin>>n;
     long long sum=0, d, totals=0;
    for(int i = 0; i < n; i++){
	cin>>d;
	sum +=  max(d-(i+1)-sum,0LL);
    } 
    cout<<sum<<endl;

   }
   return 0;
}
