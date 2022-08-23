#include <bits/stdc++.h>
using namespace std;
    int n;
int dp(int idx, int cost, string str, string &target){
  if(idx==n)return cost;
   int minc=INT_MAX;
   minc = dp(idx+1, cost+1, str+target[idx], target);
   if( target[idx]=='O' && idx>0){
       if(target[idx-1]=='R')
       minc = dp(idx+1, cost, str+'Y', target);
       if(target[idx-1]=='Y')
       minc = dp(idx+1, cost, str+'R', target);
   }
   if( target[idx]=='A' && idx>1){
       if(target[idx-1]=='R')
       minc = dp(idx+1, cost, str+'Y', target);
       if(target[idx-1]=='Y')
       minc = dp(idx+1, cost, str+'R', target);
   }
   return minc;
}
int main(){
   int T;
   cin>>T;
   for(int t=1; t<=T;t++){
    cin>>n;
    string st;
    cin>>st;
    int d=dp(0, 0,"", st); 
    cout<<"Case #"<<t<<": "<<d<<endl;

   }
   return 0;
}
