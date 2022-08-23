#include <bits/stdc++.h>
using namespace std;
int main(){
   string s;
   while(cin>>s){
      if(s=="0")break;
      int sum=0;
      for(auto i:s){
	      sum+=(i-'0');
      }
      if(sum%9==0){
	 int deg=1;
	 while(sum>9){
	   deg++;
	   int t=sum;
	   sum=0;
	   while(t) sum+=t%10, t/=10;
	 }
       cout <<s<<" is a multiple of 9 and has 9-degree "<<deg<<".\n";
      }
      else cout <<s<<" is not a multiple of 9.\n";
   }
   return 0;
}
