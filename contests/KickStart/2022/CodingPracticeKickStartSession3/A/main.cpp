#include <bits/stdc++.h>
using namespace std;
int main(){
  int T,N,M;
  cin>>T;
  for(int t=1;t<=T;t++){
   cin>>N>>M;
   long long sum=0;
   for(int i = 0 ; i < N; i++){
	long long d;
	cin>>d;
	sum+=d;
   }
   cout <<"Case #"<<t<<": "<<(sum%M)<<endl;
  }
  return 0;
}
