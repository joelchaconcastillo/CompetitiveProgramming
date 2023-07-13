#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int N,M;
   while(cin>>N>>M){
      long long realWin=0, bestWin=0;
      for(int i = 0; i < M; i++){
	   int B;
	   cin>>B;
	   long long win=0, sum=0, dae=0;
	   for(int j=0;j <N; j++){
	      int ci;
	      cin>>ci;
	      sum+=ci;
	      if(j==0)dae=ci;
	   }
	   if(sum <=B) realWin +=dae;
	   long long d = sum-dae;
	   if(d<=B){
	     d = B-d;
	     if(d >= 10000) bestWin +=10000;
	     else if(d>=1000) bestWin +=1000;
	     else if(d>=100) bestWin +=100;
	     else if(d>=10) bestWin +=10;
	     else if(d>=1) bestWin +=1;
	   }
      }
      cout << bestWin-realWin<<endl;
   }
   return 0;
}
