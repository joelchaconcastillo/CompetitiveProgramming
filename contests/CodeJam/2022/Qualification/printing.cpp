#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin>>T;
  for(int t =1; t<=T;t++){
     cout << "Case #"<<t<<": ";
     vector<long long> minC(4, LONG_MAX);
     vector<long long> C(4, LONG_MAX);
     for(int i = 0;i < 3; i++){
        cin>>C[0]>>C[1]>>C[2]>>C[3];
	for(int j = 0; j < 4; j++) minC[j]=min(minC[j], C[j]);
     }
     long long sum=0;
     for(int j = 0; j < 4; j++) sum+=minC[j];
     if( sum>=1e6){
	     auto currentSum=sum;
	     int idx=0;
	     while( currentSum-minC[idx] > 1e6) currentSum -=minC[idx], minC[idx]=0, idx++;
	     long long exceeded=max(0LL, currentSum-1000000LL);
	     minC[idx] -= exceeded;
        for(int j = 0; j < 4; j++) cout << minC[j] <<" ";
	cout <<endl;
     }
     else
	     cout <<"IMPOSSIBLE"<<endl;
  }
  return 0;
}
