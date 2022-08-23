#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   for(int t=1; t<=T;t++){
      int N, K, P;
      cin>>N>>K>>P;
      cout<<"Case "<<t<<": " << (K+P-1)%N + 1<<endl;
   }
   return 0;
}
