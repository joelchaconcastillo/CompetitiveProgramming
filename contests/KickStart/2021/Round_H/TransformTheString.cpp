#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   for(int t=1; t<=T; t++){
     string a,b;
     cin>>a>>b;
     unordered_map<int, int> f;
     for(auto i:b)f[i-'a']=1;
     int score=0;
     for(auto i:a){
	  int r=0, l=0, idx=i-'a';
         while(f[(idx+r)%26]==0) r++;
         while(f[(idx+l+26)%26]==0)l--;
	 score +=min(r, -l);
     }
     cout<<"Case #"<<t<<": "<<score<<endl;
   }
   return 0;
}
