#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int P, H, O;
   while(cin>>P>>H>>O){
      if(H > O-P) cout<<"Hunters win!"<<endl;
      else cout<<"Props win!"<<endl;
   }
   return 0;
}
