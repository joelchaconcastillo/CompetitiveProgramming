#include<bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
      int N;
      cin>>N;
      priority_queue<int> pq;
      int dp=1;
      cout<<"Case #"<<t<<":";
      for(int i = 1; i <=N; i++){
	     int d;
	     cin>>d;
	     if(d>dp){
	             pq.push(-d);
	     }
	     if(pq.size()>dp){
		dp++;
		while(!pq.empty() && -pq.top() == dp) pq.pop();
	     }
	     cout<<" ";
	     cout<<dp;
      }
      cout<<endl;
   }
   return 0;
}
