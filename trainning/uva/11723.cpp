#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int R, N, c=1;
   while(cin>>R>>N && (R!=0 && N!=0)){
      int d = ceil((R-N)/(double)N);
      if(d>26)cout<<"Case "<<c<<": impossible"<<endl;
      else cout<<"Case "<<c<<": "<<d<<endl;
      c++;
   }
   return 0;
}
