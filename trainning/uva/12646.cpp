#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int A, B, C;
   while(cin>>A>>B>>C){
      if(A!=B && A!=C) cout<<"A"<<endl;
      else if(B!=A && B!=C)cout<<"B"<<endl;
      else if(C!=A && C!=B)cout<<"C"<<endl;
      else cout <<"*"<<endl;
   }
   return 0;
}
