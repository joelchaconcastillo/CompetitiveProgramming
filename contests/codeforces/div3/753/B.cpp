#include<bits/stdc++.h>
using namespace std;

int main(){
   int T;
   cin>>T;
   while(T--){
     long long x0, n, total;
     cin>>x0>>n;
     int m=(n%4);
     int sign=(x0%2==0)?1:-1;
     if(m==0) total=x0;
     else if(m==1) total=x0-sign*n;
     else if(m==2) total=x0+sign;
     else if(m==3) total=x0+sign*(n+1);
     cout <<total<<endl;

//     for(long long i = 0, j=1; i < n; i++, j++){
//	if(x0%2==0) x0 -=j;
//	else x0+=j;
//     }
//     cout << x0<<endl;

   }
   return 0 ;
}
