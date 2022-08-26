#include <bits/stdc++.h>
using namespace std;
int main(){
   int N, K, T;
   cin>>T;
   for(int t=1;t<=T; t++){
      cin>>N>>K;
      vector<int>A(N);
      for(int i = 0 ; i < N;i++){
	 cin>>A[i];
      }
      if(2*K<N){
	cout<<"Case #"<<t<<": NO"<<endl;
	continue;
      }
      vector<int>freq(200,0);
      bool feasible=true;
      for(auto i:A){
	      freq[i]++;
	      if(freq[i]>2){
		feasible=false;
		break;
	      }
      }
     if(feasible){
	cout<<"Case #"<<t<<": YES"<<endl;
     }else{
	cout<<"Case #"<<t<<": NO"<<endl;
     }
   }
   return 0;
}
