#include <bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   vector<string> g(5, "");
   for(int i=0; i < 5; i++){
      cin>>g[i];
   }
   string res="";
   for(int i = 0; i < n; i++){
     if(g[1][4*i+1]=='*'){
      res+="1";	     
     }
     else if(g[3][4*i]=='*'){
       res+="2";
     }
     else if(g[3][4*i+2]=='*'){
       res+="3";
     }
   }
   cout << res<<endl;
   return 0;
}
