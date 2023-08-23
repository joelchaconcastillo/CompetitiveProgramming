#include <bits/stdc++.h>
using namespace std;
long long f(long long s, long long k){
   // -b/2a = (5*k-s)/40..
   long long x = (5*k-s)/40;
   x = min(x, k/4);
   long long res = s*k;
   if(x>0){
      res = max(res, (s+20*x)*(k-4*x));
   }
   x = min(x+1, k/4);
   if(x>0){
      res = max(res, (s+20*x)*(k-4*x));
   }
   return res;

}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t=1; t<=T; t++){
      long long s, k;
      cin>>s>>k;
      long long ans= s*k; //all bonus
      if( s%10 ==5){ //one accumu that will result in zeros
	ans = max(ans, (s+5)*(k-1));
      }else if(s%10){ //avoid zeros mod
	 if(s%2 == 1){ //odd number 1, 3, 7, 9: this turns it in even which will be period on 2,4,6,8
	   s += s%10;
	   k--;
	 }
	 for(int i = 0 ; i < 4; i++){ //scrolls
	    if(k>0){ //still movements..
	      ans = max(ans, f(s,k));
	    }
	    s +=s%10;
	    k--;
	 }
      }

      cout <<ans<<endl;
   }
   return 0;
}
