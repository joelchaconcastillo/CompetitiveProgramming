#include <bits/stdc++.h>
using namespace std;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int T;
   cin>>T;
   for(int tt=1;tt<=T;tt++){
     int x,a,b,c;
     int door[4]={0};
     cin>>x>>door[1]>>door[2]>>door[3];
     if(door[x]==0 || door[door[x]]==0)cout<<"NO"<<endl;
     else cout<<"YES"<<endl;

   }
   return 0;
}
