#include <bits/stdc++.h>
using namespace std;
int main(){
   int N;
   cin>>N;
   while(N--){
     int M;
     cin>>M;
     int b1=__builtin_popcount(M), b2=0, rem=0;
     while(M){
	b2+=__builtin_popcount(M%10);
	M/=10;
     } 
     cout<<b1<<" "<<b2<<endl;
   }
   return 0;
}
