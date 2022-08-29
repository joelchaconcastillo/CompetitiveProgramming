#include <bits/stdc++.h>
using namespace std;
int main(){
   int T,N;
   cin>>T;
   for(int t=1; t<=T; t++){
      cin>>N;
     vector<int> A(N);
     for(int i = 0 ; i < N; i++)cin>>A[i]; 
     if(N==1){
	cout<<"Case #"<<t<<": "<<1<<endl;
	continue;
     } 
     int breakingDays=0;
     int maxtoNow=-INT_MAX;
     for(int i = 0; i <N; i++){
	if((i==0 || A[i]>maxtoNow) && (i==N-1 || A[i]>A[i+1])) breakingDays++;
	maxtoNow=max(maxtoNow, A[i]);
     }
     cout<<"Case #"<<t<<": "<<breakingDays<<endl;
   }
   return 0;
}
